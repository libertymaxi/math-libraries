#ifndef MATRIX_H
#define MATRIX_h

#include "vector.h"

class Matrix {
    private:
        Vector elements;
        unsigned n, m;
    public:
        Matrix(Vector, int, int);
        unsigned getNRows(void);
        unsigned getNColumns(void);
        void printMatrix(void);
        Matrix operator+(Matrix);
        void operator+=(Matrix);
        Matrix operator*(double);
        void operator*=(double);
        Matrix operator-(Matrix);
        void operator-=(Matrix);
        Vector getRow(int);
        Vector getColumn(int);
        Matrix operator*(Matrix);
        void operator*=(Matrix);
        Matrix transpose(void);
        Matrix stackVertical(Matrix);
        Matrix stackHorizontal(Matrix);
        Matrix subMatrix(unsigned, unsigned, unsigned, unsigned);
        bool isSquare(void);
};

#endif