#pragma once
#include <QMainWindow>
#include "ffmpeg_rtsp.h"

class main_window : public QMainWindow {
    Q_OBJECT

public:
    main_window(QWidget* parent = nullptr);
    ~main_window();

private:

ffmpeg_rtsp* ffmpeg_rtsp_;

signals:
    void print_signal();
};