#ifndef FFMPEG_RTSP_H
#define FFMPEG_RTSP_H

#include <iostream>
 
extern "C" {
    #include "libavcodec/avcodec.h"
    #include "libavformat/avformat.h"
}


class ffmpeg_rtsp
{
public:
    ffmpeg_rtsp();
    ~ffmpeg_rtsp();

    void print_version();
private:
    /* data */

};

#endif