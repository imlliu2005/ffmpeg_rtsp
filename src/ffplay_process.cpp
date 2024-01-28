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
    // connect(play_process_, &QProcess::readyReadStandardError, this, &ffplay_process::_ready_read_standard_error);
}

void ffplay_process::_finished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "finished-exitcode: " << exitCode;
    qDebug() << "finished-exitstatus: "<< exitStatus; // QProcess::ExitStatus(NormalExit)
    qDebug() <<"finished-output-readAll:" << QString::fromLocal8Bit(play_process_->readAll());
    qDebug() <<"finished-output-readAllStandardOutput:" << QString::fromLocal8Bit(play_process_->readAllStandardOutput());;

}

void ffplay_process::_ready_read()
{
    qDebug() << "readyRead-readAll:" << QString::fromLocal8Bit(play_process_->readAll());
    qDebug() << "readyRead-readAllStandardOutput:" << QString::fromLocal8Bit(play_process_->readAllStandardOutput());
}

void ffplay_process::_ready_read_standard_output()
{
    qDebug() << "readyReadStandardOutput-readAll:" << QString::fromLocal8Bit(play_process_->readAll());
    qDebug() << "readyReadStandardOutput-readAllStandardOutput:" << QString::fromLocal8Bit(play_process_->readAllStandardOutput());
}

void ffplay_process::_ready_read_standard_error()
{
    QByteArray error = play_process_->readAllStandardError();
    qDebug() << "readyReadStandardError:" << error;
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
    qDebug() << "error_occurred:" << error;
}

void ffplay_process::start()
{
    qDebug() << "arg_list_:" << args_list_;
    play_process_->start("D:/work/ffmpeg_rtsp/build/ffplay.exe", args_list_);
}

void ffplay_process::pause()
{
    qDebug() << "send esc to play_process_...";
    // play_process_->write("p");
    // _send_key_to_ffplay(play_process_->processId(), VK_ESCAPE);
    play_process_->write("ESC\n");
    // // 等待接收响应  
    // play_process_->waitForBytesWritten();  
    // play_process_->waitForReadyRead(); 
}

void ffplay_process::stop()
{

}

// VK_ESCAPE    27	Esc
// VK_SPACE	    32	Space
void ffplay_process::_send_key_to_ffplay(DWORD process_id, BYTE virtual_key_code)
{
    qDebug() << "process_id: " << process_id << " virtual_key_code: "<< virtual_key_code; 
    if(AttachConsole(process_id))
    {
        // qDebug() << "AttachConsole success...";
        // Allocate new console
        if(!AllocConsole()) 
        {
            FreeConsole();
            qDebug() << "AllocConsole failed...";
            // return;
            AllocConsole();
        }

        keybd_event(virtual_key_code, 0, 0, 0); //Press
        Sleep(10); // wait
        keybd_event(virtual_key_code, 0, KEYEVENTF_KEYUP, 0); //Release
        Sleep(500); 

        //Detach from current process console
        FreeConsole();
    }
    else
    {
        qDebug() << "AttachConsole failed...";
    }
}