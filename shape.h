#ifndef SHAPE_H
#define SHAPE_H

#include "myglwidget.h"
#include <vector>
#include "types.h"
#include "matrix.h"

#ifdef Q_OS_MAC64
#include <OpenGL/glu.h>
#else
#include "GL/glu.h"
#endif

class Shape
{
private:
    Matrix m_pos;
    Matrix m_edges;
    Matrix *m_coord;
    std::vector<faces_4_t> *m_faces;

public:
    Shape();
    void set_matrices(std::vector<coord3d_t>* pos, std::vector<coord3d_t>* edges, std::vector<faces_4_t>* faces);
    std::vector<coord3d_t> rotate(coord3d_t axis, float angle);
    std::vector<coord3d_t> translate(coord3d_t axis, float dist);
    void draw();
};

#endif // SHAPE_H
