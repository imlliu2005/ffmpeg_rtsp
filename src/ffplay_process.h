#ifndef FFPLAY_PROCESS_H
#define FFPLAY_PROCESS_H

#include <QObject>
#include <QProcess>
#include <QStringList>

class ffplay_process : public QObject
{
    Q_OBJECT
public:
    ffplay_process(int handle, QObject *parent = nullptr);
    ~ffplay_process();
    void start();
    void pause();
    void stop();

private:
    void _init_signal_slot();
    void _finished(int exitCode, QProcess::ExitStatus exitStatus);
    void _ready_read();
    void _ready_read_standard_output();
    void _state_changed(QProcess::ProcessState state);
    void _error_occurred(QProcess::ProcessError error);

private: 
    QProcess* play_process_;
    QStringList args_list_;
    QStringList err_list_;

signals:

};

#endif // FFPLAY_PROCESS_H
