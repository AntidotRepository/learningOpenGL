CONFIG += qt
QT += widgets
QT += opengl
TEMPLATE=app

SOURCES += main.cpp \
    myglwidget.cpp \
    mywindow.cpp \
    camera.cpp \
    cube.cpp

HEADERS += \
    myglwidget.h \
    mywindow.h \
    camera.h \
    cube.h \
    types.h
