#include "ffplay_widget.h"
#include <QDebug>

ffplay_widget::ffplay_widget(QWidget *parent) : QWidget(parent)
{
    resize(800, 600);
      // 视频窗口1
    video_edit_ = new QTextEdit(this);
    video_edit_->resize(400, 400);
    // 获取窗口句柄并打印输出
    window_handle_ = video_edit_->winId();
    qDebug() << "video_edit handle:" << window_handle_;

    play_ = new ffplay_process(window_handle_, this);

    // 组合框
    video1_btn_gurop_ = new QGroupBox("video1", this); 
    gruop_box_layout_ = new QVBoxLayout();
    gruop_box_layout_->setSpacing(5);
    // 定义播放按钮
    start_btn_ = new QPushButton("开始", this);
    start_btn_->resize(74, 24);
    stop_btn_ = new QPushButton("暂停", this);
    stop_btn_->resize(74, 24);
    gruop_box_layout_->addWidget(start_btn_);
    gruop_box_layout_->addWidget(stop_btn_);
    video1_btn_gurop_->setLayout(gruop_box_layout_);

    // 主窗口布局
    plain_layout_ = new QVBoxLayout(this);

    // // 视频窗口1
    // video_edit_ = new QTextEdit(this);
    // video_edit_->resize(400, 400);
    // // 获取窗口句柄并打印输出
    // window_handle_ = video_edit_->winId();
    // qDebug() << "video_edit handle:" << window_handle_;
    
    video1_layout_ = new QHBoxLayout();
    video1_layout_->setContentsMargins(5, 10, 5, 10);
    video1_layout_->addSpacing(10);
    video1_layout_->addWidget(video_edit_);
    video1_layout_->addSpacing(10);
    video1_layout_->addWidget(video1_btn_gurop_);
    video1_layout_->addSpacing(10);

    // cmd
    cmd_label_ = new QLabel("RunCmd", this);
    cmd_label_->resize(54, 20);
    v1_label_ = new QLabel("V1", this);
    v2_label_ = new QLabel("V2", this);
    v3_label_ = new QLabel("V3", this);
    v4_label_ = new QLabel("V4", this);
    v1_line_edit_ = new QLineEdit(this);
    v2_line_edit_ = new QLineEdit(this);
    v3_line_edit_ = new QLineEdit(this);
    v4_line_edit_ = new QLineEdit(this);
    cmd_layout_ = new QHBoxLayout();

    cmd_layout_->setContentsMargins(20, 10, 20, 10);
    cmd_layout_->setSpacing(5);
    cmd_layout_->addWidget(cmd_label_);
    cmd_layout_->addWidget(v1_label_);
    cmd_layout_->addWidget(v1_line_edit_);
    cmd_layout_->addWidget(v2_label_);
    cmd_layout_->addWidget(v2_line_edit_);
    cmd_layout_->addWidget(v3_label_);
    cmd_layout_->addWidget(v3_line_edit_);
    cmd_layout_->addWidget(v4_label_);
    cmd_layout_->addWidget(v4_line_edit_);

    // all cmd
    all_cmd_label_ = new QLabel("RunAllCmd", this);
    v5_label_ = new QLabel("V1", this);
    v5_line_edit_ = new QLineEdit(this);
    v5_line_edit_->resize(154, 20);

    all_cmd_layout_ = new QHBoxLayout();
    all_cmd_layout_->setContentsMargins(20, 10, 20, 10);
    all_cmd_layout_->setSpacing(5);
    all_cmd_layout_->addWidget(all_cmd_label_);
    all_cmd_layout_->addWidget(v5_label_);
    all_cmd_layout_->addWidget(v5_line_edit_);
    all_cmd_layout_->addSpacing(10);

    plain_layout_->addLayout(video1_layout_);
    plain_layout_->addLayout(cmd_layout_);
    plain_layout_->addLayout(all_cmd_layout_);




    connect(start_btn_, &QPushButton::clicked, this,[=](){
        play_->start();
    });

    connect(stop_btn_, &QPushButton::clicked, this,[=](){
    play_->pause();
    });

}

ffplay_widget::~ffplay_widget()
{

}