#ifndef ARESTA_H
#define ARESTA_H

#include "defines.hpp"
#include <iostream>

using namespace std;

struct Aresta
{
    Aresta  *_next_edge;
    float  _weight;
    size_t _target_id;
};

#endif /* ARESTA_H */
