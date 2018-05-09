#include "shape.h"

Shape::Shape(): m_matrix(NULL)
{
}

void Shape::set_matrix(std::vector<coord3d_t>* matrix)
{
    m_matrix = Matrix(matrix);
}

std::vector<coord3d_t> Shape::rotate(coord3d_t axis, float angle)
{
    return *m_matrix.rotate(axis, angle);;
}
