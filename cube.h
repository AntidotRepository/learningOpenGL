#ifndef CUBE_H
#define CUBE_H

#include "types.h"
#include <vector>
#include "shape.h"

class Cube: public Shape
{
private:
    std::vector<coord3d_t> *m_pos;
    std::vector<coord3d_t> *m_edges;
    std::vector<coord3d_t> *m_coord;
    //std::vector<faces_4_t> *m_faces;
public:
    Cube(coord3d_t location, float width, QString textureFile="");
    std::vector<faces_4_t>* get_faces();
};

#endif // CUBE_H
