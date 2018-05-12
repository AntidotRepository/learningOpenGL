#include "camera.h"

Camera::Camera() : Shape()
{
    mat_cam_pos = new std::vector<coord3d_t>();
    mat_cam_pos->push_back({0.0f, 0.0f, 0.0f}); // Position
    mat_cam_dir = new std::vector<coord3d_t>();
    mat_cam_dir->push_back({1.0f, 0.0f, 0.0f}); // Eye direction (looking one step ahead)

    set_matrix(mat_cam_pos, mat_cam_dir);
}

void Camera::look()
{
    gluLookAt(mat_cam_pos->at(0).X, mat_cam_pos->at(0).Y, mat_cam_pos->at(0).Z,
              mat_cam_dir->at(0).X+mat_cam_pos->at(0).X, mat_cam_dir->at(0).Y+mat_cam_pos->at(0).Y, mat_cam_dir->at(0).Z+mat_cam_pos->at(0).Z,
              0, 0, 1);
}

void Camera::moveForward(float dist)
{
    translate({mat_cam_dir->at(0).X, mat_cam_dir->at(0).Y, mat_cam_dir->at(0).Z}, dist * MOVING_SPEED);
}

void Camera::moveBackward(float dist)
{
    translate({-mat_cam_dir->at(0).X, -mat_cam_dir->at(0).Y, -mat_cam_dir->at(0).Z}, dist * MOVING_SPEED);
}

void Camera::moveLeftward(float dist)
{
    translate({-mat_cam_dir->at(0).Y, mat_cam_dir->at(0).X, 0}, dist * MOVING_SPEED);
}

void Camera::moveRightward(float dist)
{
    translate({mat_cam_dir->at(0).Y, -mat_cam_dir->at(0).X, 0}, dist * MOVING_SPEED);
}

void Camera::rotateCam(float angleX, float angleY)
{
    rotate({0.0f, 0.0f, 1.0f}, angleX * ROTATION_SPEED);
    rotate({0.0f, 1.0f, 0.0f}, angleY * ROTATION_SPEED);
    std::cout<<"angleY: "<<angleY<<" X: "<<mat_cam_dir->at(0).X<<" Y: "<<mat_cam_dir->at(0).Y<<" Z: "<<mat_cam_dir->at(0).Z<<"\n";
    std::cout.flush();
}
