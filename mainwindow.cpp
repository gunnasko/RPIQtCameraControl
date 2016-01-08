#include "mainwindow.h"

#include "camerawidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto camWidget = new CameraWidget();
    setCentralWidget(camWidget);
}

MainWindow::~MainWindow()
{
}


