#ifndef CAMERA_H
#define CAMERA_H

#include "myglwidget.h"
#ifdef Q_OS_MAC64
#include <OpenGL/glu.h>
#else
#include "GL/glu.h"
#endif

class Camera
{
public:
    Camera();
    void look();
};

#endif // CAMERA_H
