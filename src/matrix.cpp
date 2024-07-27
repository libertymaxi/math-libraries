#include "matrix.h"

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Matrix :: Matrix(Vector newElements, unsigned a, unsigned b) {
    elements = newElements;
    if(a * b == elements.size()) {
        n = a;
        m = b;
    }
    else {
        n = elements.size();
        m = 1;
    }
}

unsigned Matrix :: getNRows(void) {
    return n;
}

unsigned Matrix :: getNColumns(void) {
    return m;
}

void Matrix :: printMatrix(void) {
    for(int i = 0; i < n; i++) {
        cout << "|";
        for(int j = 0; j < m; j++) {
            if(elements[i * m + j] < 0) cout << "-";
            else cout << "+";
            cout << setprecision(3) << fixed << fabs(elements[i * m + j]);
            if(j < m - 1) cout << " ";
        }
        cout << "|";
        if(i < n - 1) cout << endl;
    }
    cout << endl;
}

Matrix Matrix :: operator+(Matrix matrix) {
    if(n == matrix.n && m == matrix.m) return Matrix(elements + matrix.elements, n, m);
}

void Matrix :: operator+=(Matrix matrix) {
    if(n == matrix.n && m == matrix.m) elements += matrix.elements;
}