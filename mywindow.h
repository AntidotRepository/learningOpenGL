#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "myglwidget.h"
#include "QImage"
#include <stdlib.h>
#include <iostream>
#include "camera.h"
#include "types.h"
#include "cube.h"

#ifdef Q_OS_MAC64
#include <OpenGL/glu.h>
#else
#include "GL/glu.h"
#endif

class myWindow: public myGLWidget
{
    Q_OBJECT
private:
    GLuint texture[1];
    float f_x;
    Camera *myCamera;
    Cube *myCube;

public:
    explicit myWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void loadTexture(QString textureName);
};

#endif // MYWINDOW_H
