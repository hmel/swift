/*
 * Copyright (c) 2010-2016 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#include <iostream>

#include <QApplication>
#include <QDateTime>
#include <QFile>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QVBoxLayout>
#include <QWebEngineView>
#include <QWidget>
#include <QtDebug>
#include <QWebEngineScriptCollection>

#include <Swift/QtUI/MessageSnippet.h>
#include <Swift/QtUI/SystemMessageSnippet.h>
#include <qtwebenginecoreglobal.h>
#include <qwebengineview.h>

using namespace Swift;

class MyWidget : public QWidget {
  Q_OBJECT

public:
  MyWidget() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    chatView_ = new QWebEngineView(this);
    mainLayout->addWidget(chatView_);
    input1_ = new QLineEdit(this);
    connect(input1_, SIGNAL(returnPressed()), SLOT(addIncoming()));
    mainLayout->addWidget(input1_);
    input2_ = new QLineEdit(this);
    connect(input2_, SIGNAL(returnPressed()), SLOT(addOutgoing()));
    mainLayout->addWidget(input2_);
    input3_ = new QLineEdit(this);
    connect(input3_, SIGNAL(returnPressed()), SLOT(addSystem()));
    mainLayout->addWidget(input3_);

    resize(300, 200);

    chatView_->load(QUrl::fromLocalFile("/home/face/projects/swift/build/Swift/QtUI/chat.html"));

    auto& scripts = chatView_->page()->scripts();
    std::cout << "Scripts:" << std::endl;
    for (auto s : scripts.toList()) {
      std::cout << s.name().toStdString() << std::endl;
      std::cout << s.sourceCode().toStdString() << std::endl;
    }
  }

public slots:
  void addIncoming() {

    std::string js = R"(
   message = document.createElement('li');
    message.innerText = ')" +
                     input1_->text().toStdString() + R"('
    message.className = 'me';
    list = document.getElementById('chat');
    list.appendChild(message);
    list.lastElementChild.scrollIntoView();
      )";
    chatView_->page()->runJavaScript(js.c_str());
    input1_->clear();

    /*
    chatView_->addMessage(MessageSnippet(input1_->text(), "Me", QDateTime::currentDateTime(), "qrc:/icons/avatar.png", true, previousWasIncoming_));
    previousWasIncoming_ = true;
    previousWasOutgoing_ = false;
    previousWasSystem_ = false;
    input1_->clear();
    */
  }

  void addOutgoing() {
    QString addMessage = QString("addMessage('%1');").arg(input2_->text());
    chatView_->page()->runJavaScript(addMessage);
    input2_->clear();
    /*
    chatView_->addMessage(MessageSnippet(input2_->text(), "You", QDateTime::currentDateTime(), "qrc:/icons/avatar.png", false, previousWasOutgoing_));
    previousWasIncoming_ = false;
    previousWasOutgoing_ = true;
    previousWasSystem_ = false;
    input2_->clear();
    */
  }

  void addSystem() {
    /*
    chatView_->addMessage(SystemMessageSnippet(input3_->text(), QDateTime::currentDateTime(), previousWasSystem_));
    previousWasIncoming_ = false;
    previousWasOutgoing_ = false;
    previousWasSystem_ = true;
    input3_->clear();
    */
  }

private:
  bool previousWasIncoming_;
  bool previousWasOutgoing_;
  bool previousWasSystem_;
  QWebEngineView* chatView_;
  QLineEdit* input1_;
  QLineEdit* input2_;
  QLineEdit* input3_;
};

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  std::cout << "Chromium version: " << qWebEngineChromiumVersion() << " Patch version: " << qWebEngineChromiumSecurityPatchVersion() << std::endl;
  MyWidget w;
  w.show();
  return app.exec();
}

#include "main.moc"
