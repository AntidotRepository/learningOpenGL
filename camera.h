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
#include "defines.h"

class Camera: public Shape
{
private:
    std::vector<coord3d_t> *mat_cam_pos;
    std::vector<coord3d_t> *mat_cam_dir;

public:
    Camera();
    void look();
    void moveForward(float dist);
    void moveLeftward(float dist);
    void moveBackward(float dist);
    void moveRightward(float dist);
    void rotateCam(float angleX, float angleY);
};

#endif // CAMERA_H
