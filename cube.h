#ifndef CUBE_H
#define CUBE_H

#include "types.h"
#include <vector>
#include "shape.h"

class Cube: public Shape
{
private:
    std::vector<faces_4_t> m_faces;
public:
    Cube(std::vector<coord3d_t> coord, std::vector<faces_4_t> a_faces);
    std::vector<faces_4_t>* get_faces();
};

#endif // CUBE_H
