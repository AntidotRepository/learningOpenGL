#include "shape.h"

Shape::Shape(): m_pos(NULL), m_edges(NULL)
{
}

void Shape::set_matrices(std::vector<coord3d_t>* pos, std::vector<coord3d_t>* edges, std::vector<faces_4_t>* faces)
{
    m_pos = Matrix(pos);
    m_edges = Matrix(edges);
    m_faces = faces;
}

std::vector<coord3d_t> Shape::rotate(coord3d_t axis, float angle)
{
    return *m_edges.rotate(axis, angle);;
}

std::vector<coord3d_t> Shape::translate(coord3d_t axis, float dist)
{
    return *m_pos.translate(axis, dist);
}

void Shape::draw()
{
    glBegin(GL_QUADS);
    // Face avant
    glTexCoord2f(0.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(0).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(0).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(0).edge1).Z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(0).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(0).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(0).edge2).Z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(0).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(0).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(0).edge3).Z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(0).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(0).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(0).edge4).Z);
    // Face arrière
    glTexCoord2f(1.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(1).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(1).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(1).edge1).Z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(1).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(1).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(1).edge2).Z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(1).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(1).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(1).edge3).Z);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(1).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(1).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(1).edge4).Z);
    // Face haut
    glTexCoord2f(0.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(2).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(2).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(2).edge1).Z);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(2).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(2).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(2).edge2).Z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(2).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(2).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(2).edge3).Z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(2).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(2).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(2).edge4).Z);
    // Face bas
    glTexCoord2f(1.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(3).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(3).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(3).edge1).Z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(3).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(3).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(3).edge2).Z);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(3).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(3).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(3).edge3).Z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(3).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(3).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(3).edge4).Z);
    // Face droite
    glTexCoord2f(1.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(4).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(4).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(4).edge1).Z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(4).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(4).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(4).edge2).Z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(4).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(4).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(4).edge3).Z);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(4).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(4).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(4).edge4).Z);
    // Face gauche
    glTexCoord2f(0.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(5).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(5).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(5).edge1).Z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(5).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(5).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(5).edge2).Z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(5).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(5).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(5).edge3).Z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(5).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(5).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(5).edge4).Z);

    glEnd();
}
