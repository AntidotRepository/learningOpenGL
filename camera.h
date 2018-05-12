#ifndef CAMERA_H
#define CAMERA_H

#include "myglwidget.h"
#ifdef Q_OS_MAC64
#include <OpenGL/glu.h>
#else
#include "GL/glu.h"
#endif
#include "matrix.h"
#include "shape.h"

class Camera: public Shape
{
private:
    //Matrix *camPos;
    std::vector<coord3d_t> *mat_cam_pos;
    std::vector<coord3d_t> *mat_cam_dir;

public:
    Camera();
    void look();
};

#endif // CAMERA_H
