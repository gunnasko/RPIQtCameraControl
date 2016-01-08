#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "camerahandler.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, std::shared_ptr<CameraHandler>);
    ~MainWindow();

private:
    std::shared_ptr<CameraHandler> cameraHandler;
};

#endif // MAINWINDOW_H
