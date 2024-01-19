#ifndef FFPLAY_WIDGET_H
#define FFPLAY_WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLine>
#include <QLabel>

class ffplay_widget : public QWidget
{
    // Q_OBJECT
public:
    ffplay_widget(QWidget *parent = nullptr);
    ~ffplay_widget();

private:
    QPushButton* play_btn_;
    QTextEdit*   video_edit_;
    QGroupBox*   video1_btn_gurop_;
    
    // 布局
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
    QLine* v1_line_edit_;
    QLine* v2_line_edit_;
    QLine* v3_line_edit_;
    QLine* v4_line_edit_;


    QLabel* all_cmd_label_;
    QLabel* v5_label_;
    QLine* v5_line_edit_;

signals:

};

#endif // FFPLAY_WIDGET_H
