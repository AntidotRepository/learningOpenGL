#ifndef CUBE_H
#define CUBE_H

#include "types.h"

class Cube
{
private:
    coord3d_t coord[8];
    faces_4_t faces[6];
public:
    Cube();
    faces_4_t* get_faces();
};

#endif // CUBE_H
