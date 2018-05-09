#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "types.h"
#include "matrix.h"

class Shape
{
private:
    Matrix m_matrix;

public:
    Shape();
    void set_matrix(std::vector<coord3d_t>* matrix);
    std::vector<coord3d_t> rotate(coord3d_t axis, float angle);
    std::vector<coord3d_t> translate(coord3d_t axis, float dist);
};

#endif // SHAPE_H
