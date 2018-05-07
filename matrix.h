#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include "types.h"

class Matrix
{
private:
    std::vector<coord3d_t> my_matrix;

public:
    Matrix(std::vector<coord3d_t> coord);
    std::vector<coord3d_t>* rotate(float angle);
};

#endif // MATRIX_H
