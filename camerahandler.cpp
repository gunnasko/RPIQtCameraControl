#include "camerahandler.h"

CameraHandler::CameraHandler()
{

}

std::shared_ptr<QCamera> CameraHandler::getCamera(QCameraInfo camInfo)
{
    if(cameras.contains(camInfo))
    {
        return cameras[camInfo];
    }
    else
    {
        return NULL;
    }
}

std::shared_ptr<QCamera> CameraHandler::getCamera(int deviceId)
{
    auto camInfos = cameras.keys();
    foreach(auto camInfo, camInfos)
    {
        if(getLinuxDeviceInt(camInfo.deviceName()) == deviceId)
            return cameras[camInfo];
    }
    return NULL;
}


void CameraHandler::updateCameras()
{
    auto foundCameras = QCameraInfo::availableCameras();
    foreach(auto cameraInfo, foundCameras)
    {
        auto newCamera = std::shared_ptr<QCamera>(new QCamera(cameraInfo));
        cameras[cameraInfo] = newCamera;
    }
}

int CameraHandler::getLinuxDeviceInt(QString deviceName)
{
    return deviceName.right(1).toInt();
}

bool CameraHandler::checkCameraAvailability()
{
    if (QCameraInfo::availableCameras().count() > 0)
        return true;
    else
        return false;
}
