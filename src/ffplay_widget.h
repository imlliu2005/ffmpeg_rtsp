#ifndef FFPLAY_WIDGET_H
#define FFPLAY_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

extern "C" {
    // #include "ffplayer.h"
    #include "haha.h"
}
class ffplay_widget : public QWidget
{
    // Q_OBJECT
public:
    ffplay_widget(QWidget *parent = nullptr);
    ~ffplay_widget();

private:
    // VideoState* is_;

    // 窗口或者控件句柄
    WId window_handle_; 
    QPushButton* start_btn_;
    QPushButton* stop_btn_;
    QTextEdit* video1_edit_;
    QGroupBox* video1_btn_gurop_;
    
    // 布局
    QVBoxLayout* plain_layout_;
    QHBoxLayout* video1_layout_;
    QHBoxLayout* cmd_layout_;
    QHBoxLayout* all_cmd_layout_;
    QVBoxLayout* gruop_box_layout_;

    // cmd
    QLabel* cmd_label_;
    QLabel* v1_label_;
    QLabel* v2_label_;
    QLabel* v3_label_;
    QLabel* v4_label_;
    QLineEdit* v1_line_edit_;
    QLineEdit* v2_line_edit_;
    QLineEdit* v3_line_edit_;
    QLineEdit* v4_line_edit_;
    
    // all cmd
    QLabel* all_cmd_label_;
    QLabel* v5_label_;
    QLineEdit* v5_line_edit_;

signals:

};

#endif // FFPLAY_WIDGET_H
