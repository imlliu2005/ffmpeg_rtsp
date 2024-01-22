#ifndef FFMPEG_PROCESS_H
#define FFMPEG_PROCESS_H

#include <QObject>

class ffmpeg_process : public QObject
{
    Q_OBJECT
public:
    ffmpeg_process(QObject *parent = nullptr);
    ~ffmpeg_process();

signals:

void mySignal();

};

#endif // FFMPEG_PROCESS_H
