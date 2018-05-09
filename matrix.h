#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "types.h"
#include "math.h"
#include <iostream>

class Matrix
{
private:
    std::vector<coord3d_t> *my_matrix;

public:
    Matrix(std::vector<coord3d_t> *coord);
    std::vector<coord3d_t> *rotate(coord3d_t axis, float angle);
    std::vector<coord3d_t> *multiplicate(std::vector<coord3d_t> *mat2);
};

#endif // MATRIX_H
