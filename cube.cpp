#include "cube.h"

Cube::Cube()
{
    coord.push_back({-1.0, -1.0, 1.0});
    coord.push_back({ 1.0, -1.0, 1.0});
    coord.push_back({ 1.0,  1.0, 1.0});
    coord.push_back({-1.0,  1.0, 1.0});
    coord.push_back({-1.0, -1.0,-1.0});
    coord.push_back({-1.0,  1.0,-1.0});
    coord.push_back({ 1.0,  1.0,-1.0});
    coord.push_back({ 1.0, -1.0,-1.0});

    faces.push_back({coord[0], coord[1], coord[2], coord[3]});
    faces.push_back({coord[4], coord[5], coord[6], coord[7]});
    faces.push_back({coord[5], coord[3], coord[2], coord[6]});
    faces.push_back({coord[4], coord[7], coord[1], coord[0]});
    faces.push_back({coord[7], coord[6], coord[2], coord[1]});
    faces.push_back({coord[4], coord[0], coord[3], coord[5]});
}

std::vector<faces_4_t> *Cube::get_faces()
{
    return &faces;
}
