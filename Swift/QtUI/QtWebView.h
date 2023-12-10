/*
 * Copyright (c) 2010-2016 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <vector>
#include <QWebEngineView>

namespace Swift {
  class QtWebView : public QWebEngineView {
    Q_OBJECT
  public:
    QtWebView(QWidget* parent);
    void keyPressEvent(QKeyEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void contextMenuEvent(QContextMenuEvent* ev);
    void setFontSizeIsMinimal(bool minimum);

  signals:
    void gotFocus();
    void clearRequested();
    void fontGrowRequested();
    void fontShrinkRequested();

  protected:
    void focusInEvent(QFocusEvent* event);

  private:
    std::vector<QWebEnginePage::WebAction> filteredActions;
    bool fontSizeIsMinimal;
  };
} // namespace Swift
