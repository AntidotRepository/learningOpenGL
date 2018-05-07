#include "camera.h"

Camera::Camera()
{

}

void Camera::look()
{
    gluLookAt(10, 0, 0,
              0, 0, 0,
              0, 0, 1);
}
