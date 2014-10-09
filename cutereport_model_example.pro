QT       += core gui

TARGET = cutereport_model_example
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

# change to your cutereport location
REPORT_INSTALL_DIR = /home/vlad/tmp/alfox_build/build

INCLUDEPATH += $$REPORT_INSTALL_DIR/cutereport/include
LIBS += -L$$REPORT_INSTALL_DIR -lCuteReport -lCuteReportWidgets

RESOURCES += \
    resources.qrc
