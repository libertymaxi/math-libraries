#ifndef MATRIX_H
#define MATRIX_h

#include "vector.h"

class Matrix {
    private:
        Vector elements;
        unsigned n, m;
    public:
        Matrix(Vector, unsigned, unsigned);
        unsigned getNRows(void);
        unsigned getNColumns(void);
        void printMatrix(void);
        Matrix operator+(Matrix);
        void operator+=(Matrix);
        Matrix operator*(double);
        void operator*=(double);
        Matrix operator-(Matrix);
        void operator-=(Matrix);
};

#endif