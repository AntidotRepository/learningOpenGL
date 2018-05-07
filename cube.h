#ifndef CUBE_H
#define CUBE_H

#include "types.h"
#include <vector>

class Cube
{
private:
    std::vector<coord3d_t> coord;
    std::vector<faces_4_t> faces;
public:
    Cube();
    std::vector<faces_4_t>* get_faces();
};

#endif // CUBE_H
