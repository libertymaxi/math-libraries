#include "matrix.h"

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