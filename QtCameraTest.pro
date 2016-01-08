QT += core
QT += gui
QT += multimedia
QT += multimediawidgets

TARGET = QtCameraTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    camerahandler.cpp \
    mainwindow.cpp

target.path = /home/root
INSTALLS += target

HEADERS += \
    camerahandler.h \
    mainwindow.h
