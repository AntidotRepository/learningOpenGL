#ifndef TYPES_H
#define TYPES_H

struct coord3d_t
{
    float X;
    float Y;
    float Z;
};

/**
 * @brief The faces_4_t struct
 * Indices of edges.
 */
struct faces_4_t
{
    int edge1;
    int edge2;
    int edge3;
    int edge4;
};

#endif // TYPES_H
