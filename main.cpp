#include <QApplication>
#include <QtMultimedia>
#include <QCameraViewfinder>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

bool checkCameraAvailability()
{
    if (QCameraInfo::availableCameras().count() > 0)
        return true;
    else
        return false;
}



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qDebug()<<"Is there avaible cameraes? " << checkCameraAvailability();
    auto mainWindow = new QWidget;
    if(checkCameraAvailability())
    {
        auto cameraDevice = QCamera::availableDevices()[0];
        auto cameraInfo = QCameraInfo::availableCameras()[0];

        auto camera = new QCamera(cameraDevice);
        auto viewfinder = new QCameraViewfinder;
        camera->setViewfinder(viewfinder);

        auto cameraName = new QLabel(cameraInfo.deviceName());

        auto cameraLayout = new QVBoxLayout();
        cameraLayout->addWidget(cameraName);
        cameraLayout->addWidget(viewfinder);

        mainWindow->setLayout(cameraLayout);
        mainWindow->show();
        camera->start(); // to start the viewfinder

    }
    return app.exec();
}

