#include "matrix.h"

#define DEG_TO_RAD 0.0174533

Matrix::Matrix(std::vector<coord3d_t> *a_matrix)
{
    my_matrix = a_matrix;
}

std::vector<coord3d_t>* Matrix::rotate(coord3d_t axis, float angle)
{
    std::vector<coord3d_t> rotate_m;
    rotate_m.push_back({(float)(pow(axis.X, 2)*(1-cos(angle*DEG_TO_RAD))+cos(angle*DEG_TO_RAD)), (float)(axis.X*axis.Y*(1-cos(angle*DEG_TO_RAD))+axis.Z*sin(angle*DEG_TO_RAD)), (float)(axis.X*axis.Z*(1-cos(angle*DEG_TO_RAD))-axis.Y*sin(angle*DEG_TO_RAD))});
    rotate_m.push_back({(float)(axis.X*axis.Y*(1-cos(angle*DEG_TO_RAD))-axis.Z*sin(angle*DEG_TO_RAD)), (float)(pow(axis.Y, 2)*(1-cos(angle*DEG_TO_RAD))+cos(angle*DEG_TO_RAD)), (float)(axis.Y*axis.Z*(1-cos(angle*DEG_TO_RAD))+axis.X*sin(angle*DEG_TO_RAD))});
    rotate_m.push_back({(float)(axis.X*axis.Z*(1-cos(angle*DEG_TO_RAD))+axis.Y*sin(angle*DEG_TO_RAD)), (float)(axis.Y*axis.Z*(1-cos(angle*DEG_TO_RAD))-axis.X*sin(angle*DEG_TO_RAD)), (float)(pow(axis.Z, 2)*(1-cos(angle*DEG_TO_RAD))+cos(angle*DEG_TO_RAD))});

    multiplicate(&rotate_m);
    return my_matrix;
}

std::vector<coord3d_t>* Matrix::translate(coord3d_t axis, float dist)
{
    for(size_t i = 0; i<my_matrix->size(); i++)
    {
        my_matrix->at(i).X += axis.X * dist;
        my_matrix->at(i).Y += axis.Y * dist;
        my_matrix->at(i).Z += axis.Z * dist;
    }

    return my_matrix;
}

std::vector<coord3d_t>* Matrix::multiplicate(std::vector<coord3d_t> *mat)
{
    std::vector<coord3d_t> res;
    for(size_t i = 0; i<my_matrix->size(); i++)
    {
        res.push_back({my_matrix->at(i).X*mat->at(0).X+my_matrix->at(i).Y*mat->at(0).Y+my_matrix->at(i).Z*mat->at(0).Z,
                       my_matrix->at(i).X*mat->at(1).X+my_matrix->at(i).Y*mat->at(1).Y+my_matrix->at(i).Z*mat->at(1).Z,
                       my_matrix->at(i).X*mat->at(2).X+my_matrix->at(i).Y*mat->at(2).Y+my_matrix->at(i).Z*mat->at(2).Z});
    }

    *my_matrix = res;

    return my_matrix;
}
