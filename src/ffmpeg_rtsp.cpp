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
    qDebug() << av_version_info();
	qDebug() << "hello ffmpeg..." ;
    qDebug() << avcodec_configuration();
}