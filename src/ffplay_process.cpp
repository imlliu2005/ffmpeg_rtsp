#include "ffplay_process.h"
#include <QDebug>

ffplay_process::ffplay_process(int handle, QObject *parent) : QObject(parent)
{
    play_process_ = new QProcess(this);
    _init_signal_slot();
    // ffplay.exe -i out.mp4 -window_host 1248334  -autoexit
    args_list_ << "-i";
    args_list_ << "out.mp4";
    args_list_ << "-window_host";
    args_list_ << QString::number(handle, 10);
    args_list_ << "-autoexit";
}

ffplay_process::~ffplay_process()
{

}

void ffplay_process::_init_signal_slot() 
{
    connect(play_process_, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &ffplay_process::_finished);
    connect(play_process_, &QProcess::readyRead,this, &ffplay_process::_ready_read);
    connect(play_process_, &QProcess::readyReadStandardOutput,this, &ffplay_process::_ready_read_standard_output);
    connect(play_process_, &QProcess::stateChanged, this, &ffplay_process::_state_changed);
    connect(play_process_, &QProcess::errorOccurred, this, &ffplay_process::_error_occurred);
}

void ffplay_process::_finished(int exitCode,QProcess::ExitStatus exitStatus)
{
    qDebug()<<"finished";
    qDebug()<<exitCode;// 被调用程序的main返回的int
    qDebug()<<exitStatus;// QProcess::ExitStatus(NormalExit)
    qDebug() <<"finished-output-readAll:";
    qDebug()<<QString::fromLocal8Bit(play_process_->readAll());// ""
    qDebug()<<"finished-output-readAllStandardOutput:";
    qDebug()<<QString::fromLocal8Bit(play_process_->readAllStandardOutput());// ""
}

void ffplay_process::_ready_read()
{
    qDebug()<<"readyRead-readAll:";
    qDebug()<<QString::fromLocal8Bit(play_process_->readAll());// "hello it is ok!"
    qDebug()<<"readyRead-readAllStandardOutput:";
    qDebug()<<QString::fromLocal8Bit(play_process_->readAllStandardOutput());// ""
}

void ffplay_process::_ready_read_standard_output()
{
    qDebug()<<"readyReadStandardOutput-readAll:";
    qDebug()<<QString::fromLocal8Bit(play_process_->readAll());// ""
    qDebug()<<"readyReadStandardOutput-readAllStandardOutput:";
    qDebug()<<QString::fromLocal8Bit(play_process_->readAllStandardOutput());// ""
}

void ffplay_process::_state_changed(QProcess::ProcessState state)
{
    qDebug()<<"show state:";
    switch(state)
    {
     case QProcess::NotRunning:
        qDebug()<<"Not Running";
        break;
    case QProcess::Starting:
        qDebug()<<"Starting";
        break;
    case QProcess::Running:
        qDebug()<<"Running";
        break;
    default:
        qDebug()<<"otherState";
        break;
    }
}

 void ffplay_process::_error_occurred(QProcess::ProcessError error)
 {
    qDebug() << "error:" << error;
 }

void ffplay_process::start()
{
    qDebug() << "arg_list_:" << args_list_;
    play_process_->start("D:/work/ffmpeg_rtsp/build/ffplay.exe", args_list_);
}

void ffplay_process::pause()
{
    qDebug() << "send p to play_process_...";
    play_process_->write("p");
}

void ffplay_process::stop()
{

}