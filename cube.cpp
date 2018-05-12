#include "cube.h"

Cube::Cube(): Shape()
{
    m_pos   = new std::vector<coord3d_t>();
    m_edges = new std::vector<coord3d_t>();
    m_coord = new std::vector<coord3d_t>();
    m_faces = new std::vector<faces_4_t>();

    m_pos->push_back({0.0, 0.0, 0.0});

    m_edges->push_back({-1.0, -1.0, 1.0});
    m_edges->push_back({ 1.0, -1.0, 1.0});
    m_edges->push_back({ 1.0,  1.0, 1.0});
    m_edges->push_back({-1.0,  1.0, 1.0});
    m_edges->push_back({-1.0, -1.0,-1.0});
    m_edges->push_back({-1.0,  1.0,-1.0});
    m_edges->push_back({ 1.0,  1.0,-1.0});
    m_edges->push_back({ 1.0, -1.0,-1.0});

    m_coord->push_back({m_edges->at(0).X + m_pos->at(0).X, m_edges->at(0).Y + m_pos->at(0).Y, m_edges->at(0).Z + m_pos->at(0).Z});
    m_coord->push_back({m_edges->at(1).X + m_pos->at(0).X, m_edges->at(1).Y + m_pos->at(0).Y, m_edges->at(1).Z + m_pos->at(0).Z});
    m_coord->push_back({m_edges->at(2).X + m_pos->at(0).X, m_edges->at(2).Y + m_pos->at(0).Y, m_edges->at(2).Z + m_pos->at(0).Z});
    m_coord->push_back({m_edges->at(3).X + m_pos->at(0).X, m_edges->at(3).Y + m_pos->at(0).Y, m_edges->at(3).Z + m_pos->at(0).Z});
    m_coord->push_back({m_edges->at(4).X + m_pos->at(0).X, m_edges->at(4).Y + m_pos->at(0).Y, m_edges->at(4).Z + m_pos->at(0).Z});
    m_coord->push_back({m_edges->at(5).X + m_pos->at(0).X, m_edges->at(5).Y + m_pos->at(0).Y, m_edges->at(5).Z + m_pos->at(0).Z});
    m_coord->push_back({m_edges->at(6).X + m_pos->at(0).X, m_edges->at(6).Y + m_pos->at(0).Y, m_edges->at(6).Z + m_pos->at(0).Z});
    m_coord->push_back({m_edges->at(7).X + m_pos->at(0).X, m_edges->at(7).Y + m_pos->at(0).Y, m_edges->at(7).Z + m_pos->at(0).Z});

    faces_4_t face1 = {&m_coord->at(0), &m_coord->at(1), &m_coord->at(2), &m_coord->at(3)};
    faces_4_t face2 = {&m_coord->at(4), &m_coord->at(5), &m_coord->at(6), &m_coord->at(7)};
    faces_4_t face3 = {&m_coord->at(5), &m_coord->at(3), &m_coord->at(2), &m_coord->at(6)};
    faces_4_t face4 = {&m_coord->at(4), &m_coord->at(7), &m_coord->at(1), &m_coord->at(0)};
    faces_4_t face5 = {&m_coord->at(7), &m_coord->at(6), &m_coord->at(2), &m_coord->at(1)};
    faces_4_t face6 = {&m_coord->at(4), &m_coord->at(0), &m_coord->at(3), &m_coord->at(5)};

    m_faces->push_back(face1);
    m_faces->push_back(face2);
    m_faces->push_back(face3);
    m_faces->push_back(face4);
    m_faces->push_back(face5);
    m_faces->push_back(face6);

    set_matrix(m_pos, m_edges);
}

std::vector<faces_4_t>* Cube::get_faces()
{
    m_coord->at(0) = {m_edges->at(0).X + m_pos->at(0).X, m_edges->at(0).Y + m_pos->at(0).Y, m_edges->at(0).Z + m_pos->at(0).Z};
    m_coord->at(1) = {m_edges->at(1).X + m_pos->at(0).X, m_edges->at(1).Y + m_pos->at(0).Y, m_edges->at(1).Z + m_pos->at(0).Z};
    m_coord->at(2) = {m_edges->at(2).X + m_pos->at(0).X, m_edges->at(2).Y + m_pos->at(0).Y, m_edges->at(2).Z + m_pos->at(0).Z};
    m_coord->at(3) = {m_edges->at(3).X + m_pos->at(0).X, m_edges->at(3).Y + m_pos->at(0).Y, m_edges->at(3).Z + m_pos->at(0).Z};
    m_coord->at(4) = {m_edges->at(4).X + m_pos->at(0).X, m_edges->at(4).Y + m_pos->at(0).Y, m_edges->at(4).Z + m_pos->at(0).Z};
    m_coord->at(5) = {m_edges->at(5).X + m_pos->at(0).X, m_edges->at(5).Y + m_pos->at(0).Y, m_edges->at(5).Z + m_pos->at(0).Z};
    m_coord->at(6) = {m_edges->at(6).X + m_pos->at(0).X, m_edges->at(6).Y + m_pos->at(0).Y, m_edges->at(6).Z + m_pos->at(0).Z};
    m_coord->at(7) = {m_edges->at(7).X + m_pos->at(0).X, m_edges->at(7).Y + m_pos->at(0).Y, m_edges->at(7).Z + m_pos->at(0).Z};

    return m_faces;
}
