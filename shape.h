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
    Shape(std::vector<coord3d_t> coord);
    std::vector<coord3d_t> rotate(float angle);
};

#endif // SHAPE_H
