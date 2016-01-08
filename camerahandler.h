#ifndef CAMERAS_H
#define CAMERAS_H

#include "camera.h"
#include <QMap>
#include <memory>

class CameraHandler
{
public:
    CameraHandler();
    void updateCameras();
    bool checkCameraAvailability();
    std::shared_ptr<QCamera> getCamera(QCameraInfo);
    std::shared_ptr<QCamera> getCamera(int deviceId);

    static int getLinuxDeviceInt(QString);

private:
    QMap<QCameraInfo, std::shared_ptr<QCamera>> cameras;
};

inline bool operator<(const QCameraInfo &c1, const QCameraInfo &c2)
{
    int c1Num = CameraHandler::getLinuxDeviceInt(c1.deviceName());
    int c2Num = CameraHandler::getLinuxDeviceInt(c2.deviceName());
    if (c1Num < c2Num)
        return true;
    else
        return false;
}


#endif // CAMERAS_H
