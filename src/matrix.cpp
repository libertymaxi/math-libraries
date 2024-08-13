#include "matrix.h"

#include <iostream>
#include <iomanip>
#include <cmath>

Matrix :: Matrix(Vector newElements, int a, int b) {
    if(a < 0 || b < 0) throw std::invalid_argument("Both arguments must be positive numbers");
    else if(a * b != newElements.size()) throw std::invalid_argument("Total number of elements(a * b) must correspond to the size of the vector");
    elements = newElements;
    n = a;
    m = b;
}

unsigned Matrix :: getNRows(void) {
    return n;
}

unsigned Matrix :: getNColumns(void) {
    return m;
}

void Matrix :: printMatrix(void) {
    for(int i = 0; i < n; i++) {
        std::cout << "|";
        for(int j = 0; j < m; j++) {
            if(elements[i * m + j] < 0) std::cout << "-";
            else std::cout << "+";
            std::cout << std::setprecision(3) << std::fixed << fabs(elements[i * m + j]);
            if(j < m - 1) std::cout << " ";
        }
        std::cout << "|";
        if(i < n - 1) std::cout << std::endl;
    }
    std::cout << std::endl;
}

Matrix Matrix :: operator+(Matrix matrix) {
    if(n != matrix.n || m != matrix.m) throw std::invalid_argument("Sizes of the 2 matrices must coincide");
    return Matrix(elements + matrix.elements, n, m);
}

void Matrix :: operator+=(Matrix matrix) {
    if(n != matrix.n || m != matrix.m) throw std::invalid_argument("Sizes of the 2 matrices must coincide");
    elements += matrix.elements;
}

Matrix Matrix :: operator*(double number) {
    return Matrix(elements * number, n, m);
}

void Matrix :: operator*=(double number) {
    elements *= number;
}

Matrix Matrix :: operator-(Matrix matrix) {
    if(n != matrix.n || m != matrix.m) throw std::invalid_argument("Sizes of the 2 matrices must coincide");
    return Matrix(elements - matrix.elements, n, m);
}

void Matrix :: operator-=(Matrix matrix) {
    if(n != matrix.n || m != matrix.m) throw std::invalid_argument("Sizes of the 2 matrices must coincide");
    elements -= matrix.elements;
}

Vector Matrix :: getRow(int row) {
    if(row < 0 || row >= n) throw std::invalid_argument("Argument must be positive and less than the number of rows");
    std::vector<double> aux;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == row) aux.push_back(elements[i * m + j]);
        }
    }
    return Vector(aux);
}

Vector Matrix :: getColumn(int column) {
    if(column < 0 || column >= m) throw std::invalid_argument("Argument must be positive and less than the number of columns");
    std::vector<double> aux;
    for(int i = 0; i < n; i++) {
        aux.push_back(elements[i * m + column]);
    }
    return Vector(aux);
}

Matrix Matrix :: operator*(Matrix matrix) {
    if(m != matrix.n) throw std::invalid_argument("matrix sizes are not compatible");
    std::vector<double> newMatrix;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < matrix.m; j++) {
            newMatrix.push_back(getRow(i) * matrix.getColumn(j));
        }
    }
    return Matrix(Vector(newMatrix), n, matrix.m);
}

void Matrix :: operator*=(Matrix matrix) {
    elements = operator*(matrix).elements;
}

Matrix Matrix :: transpose(void) {
    Vector newElements;
    for(int i = 0; i < m; i++) {
        newElements = newElements.attach(getColumn(i));
    }
    return Matrix(newElements, m, n);
}

Matrix Matrix :: stackVertical(Matrix matrix) {
    if(m != matrix.m) throw std::invalid_argument("Both matrices must have the same number of columns");
    return Matrix(elements.attach(matrix.elements), n + matrix.n, m);
}

Matrix Matrix :: stackHorizontal(Matrix matrix) {
    if(n != matrix.n) throw std::invalid_argument("Both matrices must have the same number of rows");
    Vector newElements;
    for(int i = 0; i < n; i++) {
        newElements = newElements.attach(getRow(i).attach(matrix.getRow(i)));
    }
    return Matrix(newElements, n, m + matrix.m);
}

Matrix Matrix :: subMatrix(unsigned a, unsigned b, unsigned c, unsigned d) {
    std::vector<double> newElements;
    if(!(a >= 0 && b < n && a <= b && c >= 0 && d < n && c <= d)) throw std::invalid_argument("Invalid indices");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i >= a && i <= b && j >= c && j <= d) {
                newElements.push_back(elements[i * m + j]);
            }
        }
    }
    return Matrix(Vector(newElements), b - a + 1, d - c + 1);
}

bool Matrix :: isSquare(void) {
    return (n == m) ? true : false;
}