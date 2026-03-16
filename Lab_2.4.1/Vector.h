#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vector {
private:
    int* num;
    int size;

public:
    Vector();
    Vector(int s);
    Vector(int s, const int* arr);
    Vector(const Vector& other);
    ~Vector();

    int getSize() const;
    void setSize(int s);
    int getElement(int index) const;
    void setElement(int index, int value);

    double norm() const;

    operator string() const;
    Vector& operator=(const Vector& other);
    int& operator[](int index);

    Vector& operator++();       
    Vector operator++(int);    
    Vector& operator--();       
    Vector operator--(int);

    Vector operator*(int scalar) const;

    friend bool operator==(const Vector& v1, const Vector& v2);
    friend bool operator!=(const Vector& v1, const Vector& v2);
    friend bool operator>(const Vector& v1, const Vector& v2);
    friend bool operator<(const Vector& v1, const Vector& v2);
    friend bool operator>=(const Vector& v1, const Vector& v2);
    friend bool operator<=(const Vector& v1, const Vector& v2);

    friend ostream& operator<<(ostream& out, const Vector& v);
    friend istream& operator>>(istream& in, Vector& v);
};