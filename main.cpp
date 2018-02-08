#include "logbrowser.h"
#include <QApplication>
#include <QDebug>
#include <QPointer>

QPointer<LogBrowser> logBrowser;

void myMessageOutput(QtMsgType type, const char* msg)
{
    if (logBrowser)
        logBrowser->outputMessage(type, msg);
}

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if (logBrowser)
        logBrowser->outputMessage(type, context, msg);
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    logBrowser = new LogBrowser;
    qInstallMessageHandler(myMessageOutput);

    qDebug() << "test for debug";
    int result = a.exec();
    qDebug() << "application exec return result =" << result;

    delete logBrowser;
    return result;
}
