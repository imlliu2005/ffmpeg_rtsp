#include "main_window.h"
#include "ffplay_widget.h"
#include <QFile>
#include <QTextStream>
#include <QApplication>
#pragma comment(lib, "user32.lib")

void outLogMessageToFile(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString message;
    QString app_run_addr;
    message = qFormatLogMessage(type, context, msg);
    message.append("\r\n");

    //获取程序当前运行目录
    QString current_PathName = QCoreApplication::applicationDirPath();
    if(QFile::exists(current_PathName)==false)
    {
        app_run_addr = "debug.log";
    }
    else
    {
        app_run_addr = current_PathName + "/"+"debug.log";
    }
    QFile file(app_run_addr);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        file.write(message.toLocal8Bit());
    }
    file.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // qSetMessagePattern("[%{time yyyy-MM-dd hh:mm:ss.zzz}] %{file} %{line} %{function} %{message}");
    qSetMessagePattern("[%{time yyyy-MM-dd hh:mm:ss.zzz}] %{message}");
    //初始化qdebug的输出重定向到文件
    qInstallMessageHandler(outLogMessageToFile);
    ffplay_widget w;
    w.show();
    return a.exec();
}