#include "main_window.h"
#include <QPushButton>


main_window::main_window(QWidget* parent)
    : QMainWindow(parent)
{

    ffmpeg_rtsp_ = new ffmpeg_rtsp();
    this->resize(800, 600);

    QPushButton* btn = new QPushButton("print", this);
    btn->resize(100, 40);
    connect(btn, &QPushButton::clicked, this, [=](){
        ffmpeg_rtsp_->print_version();
    });
}

main_window::~main_window()
{
    if(ffmpeg_rtsp_) 
    {
        delete ffmpeg_rtsp_;
        ffmpeg_rtsp_ = nullptr;
    }
}