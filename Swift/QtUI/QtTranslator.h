/*
 * Copyright (c) 2011-2016 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <QCoreApplication>
#include <QDateTime>
#include <QLocale>

#include <Swift/Controllers/Translator.h>

#include <Swift/QtUI/QtSwiftUtil.h>

class QtTranslator : public Swift::Translator {
public:
  QtTranslator() {}

  virtual std::string translate(const std::string& text, const std::string& context) {
#if QT_VERSION >= 0x050000
    return std::string(QCoreApplication::translate(context.c_str(), text.c_str(), nullptr).toUtf8());
#else
    return std::string(QCoreApplication::translate(context.c_str(), text.c_str(), 0, QCoreApplication::UnicodeUTF8).toUtf8());
#endif
  }

  virtual std::string ptimeToHumanReadableString(const boost::posix_time::ptime& time) {
    QLocale loc = QLocale::system();
    loc.dateTimeFormat();
    auto t = QDateTime::fromTime_t(posixTimeToTimeT(time));
    QString qstr = loc.toString(t);
    std::string prev = Q2PSTRING(QDateTime::fromTime_t(posixTimeToTimeT(time)).toString(Qt::SystemLocaleLongDate));
    Q_ASSERT(prev == qstr.toStdString());
    return qstr.toStdString();
  }

private:
  static std::time_t posixTimeToTimeT(boost::posix_time::ptime pt) {
    return std::time_t((pt - boost::posix_time::ptime(boost::gregorian::date(1970, 1, 1))).total_seconds());
  }
};
