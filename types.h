#ifndef TYPES_H
#define TYPES_H

struct coord3d_t
{
    float X;
    float Y;
    float Z;
};

struct faces_4_t
{
    coord3d_t edge1;
    coord3d_t edge2;
    coord3d_t edge3;
    coord3d_t edge4;
};

#endif // TYPES_H
