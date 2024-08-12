#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

class Vector {
    private:
        std::vector<double> elements;
    public:
        Vector() = default;
        Vector(std::vector<double>);
        Vector(unsigned);
        unsigned size(void);
        void printVector(void);
        double operator[](int);
        Vector operator+(Vector);
        void operator+=(Vector);
        Vector operator*(double);
        void operator*=(double);
        Vector operator-(Vector);
        void operator-=(Vector);
        Vector attach(Vector);
        double operator*(Vector);
        Vector subVector(int, int);
};

#endif