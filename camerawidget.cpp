#include "camerawidget.h"

#include <QCameraViewfinder>
#include <QListView>
#include <QHBoxLayout>

CameraWidget::CameraWidget()
{
    cameraHandler = std::unique_ptr<CameraHandler>(new CameraHandler);
    cameraHandler->updateCameras();

    auto camViewWidget = new QCameraViewfinder(this);
    auto camera = cameraHandler->getCamera(cameraHandler->getCameraInfo().first());
    camera->setViewfinder(camViewWidget);
    camera->start();

    auto camNameModel = createCameraInfoModel();
    auto camNameListView = new QListView(this);
    camNameListView->setModel(camNameModel);

    auto layout = new QHBoxLayout(this);
    layout->addWidget(camViewWidget);
    layout->addWidget(camNameListView);
}

QStandardItemModel *CameraWidget::createCameraInfoModel()
{
    auto returnModel = new QStandardItemModel;
    auto cameraInfos = cameraHandler->getCameraInfo();
    foreach(auto cameraInfo, cameraInfos)
    {
        auto *camInfoItem = new QStandardItem(cameraInfo.deviceName());
        returnModel->appendRow(camInfoItem);
    }
    return returnModel;
}
