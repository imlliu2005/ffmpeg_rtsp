#pragma once
#include <QMainWindow>
#include "ffplay_widget.h"

class main_window : public QMainWindow {
    Q_OBJECT

public:
    main_window(QWidget* parent = nullptr);
    ~main_window();

private:
    ffplay_widget* ffplay_widget_;

signals:
 
};