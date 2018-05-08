#include "cube.h"

Cube::Cube(std::vector<coord3d_t> coord, std::vector<faces_4_t> a_faces)
    : Shape(coord), m_faces(a_faces)
{
}

std::vector<faces_4_t>* Cube::get_faces()
{
    return &m_faces;
}
