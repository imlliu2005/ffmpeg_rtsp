#include "main_window.h"

main_window::main_window(QWidget* parent)
    : QMainWindow(parent)
{
    // 重置窗口大小
    resize(800, 600);
    ffplay_widget_ = new ffplay_widget(this);
    setCentralWidget(ffplay_widget_);

}

main_window::~main_window()
{

}