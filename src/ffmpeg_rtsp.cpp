#include "ffmpeg_rtsp.h"
#include <QDebug>

ffmpeg_rtsp::ffmpeg_rtsp()
{
}

ffmpeg_rtsp::~ffmpeg_rtsp()
{
}

void ffmpeg_rtsp::print_version()
{
    qDebug() << "hello ffmpeg..." ;
    qDebug() << "ffmpeg version info:" << av_version_info();
    qDebug() << "avcodec configure:" << avcodec_configuration();
}