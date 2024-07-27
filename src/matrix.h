#ifndef MATRIX_H
#define MATRIX_h

#include "vector.h"

class Matrix {
    private:
        Vector elements;
        unsigned n, m;
    public:
        Matrix(Vector, unsigned, unsigned);
};

#endif