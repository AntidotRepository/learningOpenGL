CONFIG += qt
QT += widgets
QT += opengl
TEMPLATE=app

SOURCES += main.cpp \
    myglwidget.cpp \
    mywindow.cpp \
    camera.cpp

HEADERS += \
    myglwidget.h \
    mywindow.h \
    camera.h
