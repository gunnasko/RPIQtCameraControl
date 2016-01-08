#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QStandardItemModel>

#include "camerahandler.h"

class CameraWidget : public QWidget
{
    Q_OBJECT
public:
    CameraWidget();

private:
    QStandardItemModel *createCameraInfoModel();
    std::unique_ptr<CameraHandler> cameraHandler;
};

#endif // CAMERAWIDGET_H
