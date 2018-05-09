#include "cube.h"

Cube::Cube(): Shape()
{
    m_coord = new std::vector<coord3d_t>();
    m_faces = new std::vector<faces_4_t>();

    m_coord->push_back({-1.0, -1.0, 1.0});
    m_coord->push_back({ 1.0, -1.0, 1.0});
    m_coord->push_back({ 1.0,  1.0, 1.0});
    m_coord->push_back({-1.0,  1.0, 1.0});
    m_coord->push_back({-1.0, -1.0,-1.0});
    m_coord->push_back({-1.0,  1.0,-1.0});
    m_coord->push_back({ 1.0,  1.0,-1.0});
    m_coord->push_back({ 1.0, -1.0,-1.0});

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

    set_matrix(m_coord);
}

std::vector<faces_4_t>* Cube::get_faces()
{
    return m_faces;
}
