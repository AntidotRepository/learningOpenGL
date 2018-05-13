#include "shape.h"

Shape::Shape(): m_pos(NULL), m_edges(NULL)
{
}

void Shape::set_matrices(std::vector<coord3d_t>* pos, std::vector<coord3d_t>* edges, std::vector<faces_4_t>* faces)
{
    m_pos = Matrix(pos);
    m_edges = Matrix(edges);
    m_faces = faces;

    if(m_textureFile != "") // If a texture is provided
    {
        loadTexture();
    }
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
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
    // Face avant
    for(int i = 0; i<2; i++)
    {
        glTexCoord2f(m_text->at(m_textFaces->at(i).edge1).X, m_text->at(m_textFaces->at(i).edge1).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(i).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(i).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(i).edge1).Z);
        glTexCoord2f(m_text->at(m_textFaces->at(i).edge2).X, m_text->at(m_textFaces->at(i).edge2).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(i).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(i).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(i).edge2).Z);
        glTexCoord2f(m_text->at(m_textFaces->at(i).edge3).X, m_text->at(m_textFaces->at(i).edge3).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(i).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(i).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(i).edge3).Z);
        glTexCoord2f(m_text->at(m_textFaces->at(i).edge4).X, m_text->at(m_textFaces->at(i).edge4).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(i).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(i).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(i).edge4).Z);
    }
 /*   glTexCoord2f(m_text->at(m_textFaces->at(0).edge1).X, m_text->at(m_textFaces->at(0).edge1).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(0).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(0).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(0).edge1).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(0).edge2).X, m_text->at(m_textFaces->at(0).edge2).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(0).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(0).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(0).edge2).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(0).edge3).X, m_text->at(m_textFaces->at(0).edge3).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(0).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(0).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(0).edge3).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(0).edge4).X, m_text->at(m_textFaces->at(0).edge4).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(0).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(0).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(0).edge4).Z);
    // Face arrière
    glTexCoord2f(m_text->at(m_textFaces->at(1).edge1).X, m_text->at(m_textFaces->at(1).edge1).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(1).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(1).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(1).edge1).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(1).edge2).X, m_text->at(m_textFaces->at(1).edge2).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(1).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(1).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(1).edge2).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(1).edge3).X, m_text->at(m_textFaces->at(1).edge3).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(1).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(1).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(1).edge3).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(1).edge4).X, m_text->at(m_textFaces->at(1).edge4).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(1).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(1).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(1).edge4).Z);
    // Face haut
    glTexCoord2f(m_text->at(m_textFaces->at(2).edge1).X, m_text->at(m_textFaces->at(2).edge1).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(2).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(2).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(2).edge1).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(2).edge2).X, m_text->at(m_textFaces->at(2).edge2).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(2).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(2).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(2).edge2).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(2).edge3).X, m_text->at(m_textFaces->at(2).edge3).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(2).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(2).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(2).edge3).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(2).edge4).X, m_text->at(m_textFaces->at(2).edge4).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(2).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(2).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(2).edge4).Z);
    // Face bas
    glTexCoord2f(m_text->at(m_textFaces->at(3).edge1).X, m_text->at(m_textFaces->at(3).edge1).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(3).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(3).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(3).edge1).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(3).edge2).X, m_text->at(m_textFaces->at(3).edge2).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(3).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(3).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(3).edge2).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(3).edge3).X, m_text->at(m_textFaces->at(3).edge3).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(3).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(3).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(3).edge3).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(3).edge4).X, m_text->at(m_textFaces->at(3).edge4).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(3).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(3).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(3).edge4).Z);
    // Face droite
    glTexCoord2f(m_text->at(m_textFaces->at(4).edge1).X, m_text->at(m_textFaces->at(4).edge1).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(4).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(4).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(4).edge1).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(4).edge2).X, m_text->at(m_textFaces->at(4).edge2).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(4).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(4).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(4).edge2).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(4).edge3).X, m_text->at(m_textFaces->at(4).edge3).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(4).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(4).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(4).edge3).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(4).edge4).X, m_text->at(m_textFaces->at(4).edge4).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(4).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(4).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(4).edge4).Z);
    // Face gauche
    glTexCoord2f(m_text->at(m_textFaces->at(5).edge1).X, m_text->at(m_textFaces->at(5).edge1).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(5).edge1).X, m_pos.get(0).Y + m_edges.get(m_faces->at(5).edge1).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(5).edge1).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(5).edge2).X, m_text->at(m_textFaces->at(5).edge2).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(5).edge2).X, m_pos.get(0).Y + m_edges.get(m_faces->at(5).edge2).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(5).edge2).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(5).edge3).X, m_text->at(m_textFaces->at(5).edge3).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(5).edge3).X, m_pos.get(0).Y + m_edges.get(m_faces->at(5).edge3).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(5).edge3).Z);
    glTexCoord2f(m_text->at(m_textFaces->at(5).edge4).X, m_text->at(m_textFaces->at(5).edge4).Y); glVertex3f(m_pos.get(0).X + m_edges.get(m_faces->at(5).edge4).X, m_pos.get(0).Y + m_edges.get(m_faces->at(5).edge4).Y, m_pos.get(0).Z + m_edges.get(m_faces->at(5).edge4).Z);
*/
    glEnd();
}

void Shape::loadTexture()
{
    QImage qim_Texture;
    QImage qim_TempTexture;
    if(qim_TempTexture.load(m_textureFile))
    {
        qim_Texture = QGLWidget::convertToGLFormat(qim_TempTexture);
        glGenTextures(1, &texture[0]);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, qim_Texture.width(), qim_Texture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, qim_Texture.bits());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    else
    {
        std::cout<<"Could not load texture!";
    }
}
