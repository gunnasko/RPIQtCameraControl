#include <QApplication>
#include <QtMultimedia>
#include <QCameraViewfinder>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto mainWindow = new MainWindow();
    mainWindow->show();

    return app.exec();
}

