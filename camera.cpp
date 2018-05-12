#include "camera.h"

Camera::Camera() : Shape()
{
    mat_cam_pos = new std::vector<coord3d_t>();
    mat_cam_pos->push_back({0, 0, 0}); // Position
    mat_cam_dir = new std::vector<coord3d_t>();
    mat_cam_dir->push_back({0, 1, 0}); // Eye direction (looking one step ahead)

    set_matrix(mat_cam_pos, mat_cam_dir);
}

void Camera::look()
{
    gluLookAt(mat_cam_pos->at(0).X, mat_cam_pos->at(0).Y, mat_cam_pos->at(0).Z,
              mat_cam_dir->at(0).X+mat_cam_pos->at(0).X, mat_cam_dir->at(0).Y+mat_cam_pos->at(0).Y, mat_cam_dir->at(0).Z+mat_cam_pos->at(0).Z,
              0, 0, 1);
}
