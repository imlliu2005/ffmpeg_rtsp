#include "ffplay_widget.h"
#include <QDebug>

ffplay_widget::ffplay_widget(QWidget *parent) : QWidget(parent)
{
    resize(400, 300);
    // 定义播放按钮
    play_btn_ = new QPushButton("开始", this);
    play_btn_->resize(80, 30);

    video_edit_ = new QTextEdit(this);
    video_edit_->resize(400, 400);

     // 获取窗口句柄并打印输出
    WId window_handle = video_edit_->winId();
    qDebug() << "video_edit handle:" << window_handle;

    // 组合框
    video1_btn_gurop_ = new QGroupBox("video1", this);
    video1_btn_gurop_->setContentsMargins(0, 0, 0, 0);
    gruop_box_layout_ = new QVBoxLayout(this);
    gruop_box_layout_->addWidget(play_btn_);
    video1_btn_gurop_->setLayout(gruop_box_layout_);

    // 视频窗口1
    video1_layout_ = new QHBoxLayout(this);
    video1_layout_->setContentsMargins(5, 10, 5, 10);
    video1_layout_->addSpacing(10);
    video1_layout_->addWidget(video_edit_);
    video1_layout_->addSpacing(10);
    video1_layout_->addWidget(video1_btn_gurop_);
    video1_layout_->addSpacing(10);

    // cmd
    cmd_label_ = new QLabel("RunCmd", this);
    v1_label_ = new QLabel("V1", this);
    v2_label_ = new QLabel("V2", this);
    v3_label_ = new QLabel("V3", this);
    v4_label_ = new QLabel("V4", this);
    v1_line_edit_ = new QLine();
    v2_line_edit_ = new QLine();
    v3_line_edit_ = new QLine();
    v4_line_edit_ = new QLine();

    // all cmd
    all_cmd_label_ = new QLabel("RunAllCmd", this);
    v5_label_ = new QLabel("V1", this);

}

ffplay_widget::~ffplay_widget()
{

}