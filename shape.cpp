#include "shape.h"

Shape::Shape(): m_matrix_pos(NULL), m_matrix_edges(NULL)
{
}

void Shape::set_matrix(std::vector<coord3d_t>* m_pos, std::vector<coord3d_t>* m_edges)
{
    m_matrix_pos = Matrix(m_pos);
    m_matrix_edges = Matrix(m_edges);
}

std::vector<coord3d_t> Shape::rotate(coord3d_t axis, float angle)
{
    return *m_matrix_edges.rotate(axis, angle);;
}

std::vector<coord3d_t> Shape::translate(coord3d_t axis, float dist)
{
    return *m_matrix_pos.translate(axis, dist);
}
