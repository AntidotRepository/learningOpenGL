#include "camera.h"

Camera::Camera() : Shape()
{
    mat_cam = {{0, 0, 0}, // Position
               {0, 1, 0}};// Eye direction (looking one step ahead)
    //camPos = new Matrix(&mat_cam);
    set_matrix(&mat_cam);
}

void Camera::look()
{
    gluLookAt(mat_cam.at(0).X, mat_cam.at(0).Y, mat_cam.at(0).Z,
              mat_cam.at(1).X, mat_cam.at(1).Y, mat_cam.at(1).Z,
              0, 0, 1);
}
