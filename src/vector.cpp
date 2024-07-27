#include "vector.h"

#include <iostream>
#include <iomanip>
#include <cmath>

Vector :: Vector(vector<double> newElements) {
    elements = newElements;
}

Vector :: Vector(unsigned nElements) {
    for(int i = 0; i < nElements; i++) elements.push_back(0.0);
}

unsigned Vector :: size(void) {
    return elements.size();
}

void Vector :: printVector(void) {
    cout << "[";
    for(int i = 0; i < elements.size(); i++) {
        if(elements[i] < 0) cout << "-";
        else cout << "+";
        cout << setprecision(3) << fixed << fabs(elements[i]);
        if(i < elements.size() - 1) cout << " ";
    }
    cout << "]" << endl;
}

double Vector :: operator[](unsigned index) {
    return elements[index];
}

Vector Vector :: operator+(Vector vectorOperator) {
    vector<double> newElements;
    if(elements.size() < vectorOperator.elements.size()) {
        for(int i = 0; i < elements.size(); i++) {
            newElements.push_back(elements[i] + vectorOperator.elements[i]);
        }
        for(int j = elements.size(); j < vectorOperator.elements.size(); j++) {
            newElements.push_back(vectorOperator.elements[j]);
        }
    }
    else {
        for(int i = 0; i < vectorOperator.elements.size(); i++) {
            newElements.push_back(elements[i] + vectorOperator.elements[i]);
        }
        for(int j = vectorOperator.elements.size(); j < elements.size(); j++) {
            newElements.push_back(elements[j]);
        }
    }
    return Vector(newElements);
}

void Vector :: operator+=(Vector vectorOperator) {
    elements = operator+(vectorOperator).elements;
}

Vector Vector :: operator*(double number) {
    vector<double> newElements;
    for(int i = 0; i < elements.size(); i++) {
        newElements.push_back(elements[i] * number);
    }
    return Vector(newElements);
}

void Vector :: operator*=(double number) {
    elements = Vector(operator*(number)).elements;
}

Vector Vector :: operator-(Vector vectorOperator) {
    return operator+(vectorOperator * -1);
}

void Vector :: operator-=(Vector vectorOperator) {
    elements = Vector(operator-(vectorOperator)).elements;
}

Vector Vector :: attach(Vector vectorOperator) {
    vector<double> newElements = elements;
    for(int i = 0; i < vectorOperator.elements.size(); i++) {
        newElements.push_back(vectorOperator.elements[i]);
    }
    return Vector(newElements);
}