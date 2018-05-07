#include "cube.h"

Cube::Cube()
{
    coord[0] = {-1.0, -1.0, 1.0};
    coord[1] = { 1.0, -1.0, 1.0};
    coord[2] = { 1.0,  1.0, 1.0};
    coord[3] = {-1.0,  1.0, 1.0};
    coord[4] = {-1.0, -1.0,-1.0};
    coord[5] = {-1.0,  1.0,-1.0};
    coord[6] = { 1.0,  1.0,-1.0};
    coord[7] = { 1.0, -1.0,-1.0};

    faces[0] = {coord[0], coord[1], coord[2], coord[3]};
    faces[1] = {coord[4], coord[5], coord[6], coord[7]};
    faces[2] = {coord[5], coord[3], coord[2], coord[6]};
    faces[3] = {coord[4], coord[7], coord[1], coord[0]};
    faces[4] = {coord[7], coord[6], coord[2], coord[1]};
    faces[5] = {coord[4], coord[0], coord[3], coord[5]};
}

faces_4_t* Cube::get_faces()
{
    return faces;
}
