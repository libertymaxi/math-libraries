#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

using namespace std;

class Vector {
    private:
        vector<double> elements;
    public:
        Vector() = default;
        Vector(vector<double>);
        Vector(unsigned);
        unsigned size(void);
        void printVector(void);
        double operator[](unsigned);
        Vector operator+(Vector);
        void operator+=(Vector);
        Vector operator*(double);
        void operator*=(double);
        Vector operator-(Vector);
        void operator-=(Vector);
        Vector attach(Vector);
        double operator*(Vector);
};

#endif