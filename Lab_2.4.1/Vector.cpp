#include "Vector.h"
#include <sstream>
#include <cmath>

Vector::Vector() : size(0), num(nullptr) {}

Vector::Vector(int s) : size(s) {
    if (size > 0) {
        num = new int[size];
        for (int i = 0; i < size; i++) num[i] = 0;
    }
    else num = nullptr;
}

Vector::Vector(int s, const int* arr) : size(s) {
    if (size > 0) {
        num = new int[size];
        for (int i = 0; i < size; i++) num[i] = arr[i];
    }
    else num = nullptr;
}

Vector::Vector(const Vector& other) : size(other.size) {
    if (size > 0) {
        num = new int[size];
        for (int i = 0; i < size; i++) num[i] = other.num[i];
    }
    else num = nullptr;
}

Vector::~Vector() {
    delete[] num;
}

int Vector::getSize() const {
    return size;
}

void Vector::setSize(int s) {
    if (s < 0 || s == size) return;

    int* temp = nullptr;
    if (s > 0) {
        temp = new int[s];
        int minSize = (size < s) ? size : s;
        for (int i = 0; i < minSize; i++) temp[i] = num[i];
        for (int i = minSize; i < s; i++) temp[i] = 0;
    }
    delete[] num;
    num = temp;
    size = s;
}

int Vector::getElement(int index) const {
    if (index >= 0 && index < size) return num[index];
    return 0;
}

void Vector::setElement(int index, int value) {
    if (index >= 0 && index < size) num[index] = value;
}

double Vector::norm() const {
    long sum = 0;
    for (int i = 0; i < size; i++) sum += (long)num[i] * num[i];
    return sqrt(static_cast<double>(sum));
}

Vector::operator string() const {
    stringstream ss;
    ss << "(";
    for (int i = 0; i < size; i++) {
        ss << num[i] << (i == size - 1 ? "" : ", ");
    }
    ss << ")";
    return ss.str();
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] num;
        size = other.size;
        if (size > 0) {
            num = new int[size];
            for (int i = 0; i < size; i++) num[i] = other.num[i];
        }
        else {
            num = nullptr;
        }
    }
    return *this;
}

int& Vector::operator[](int index) {
    if (index >= 0 && index < size) return num[index];
    static int dummy = 0;
    return dummy;
}

// ДОДАНО: Реалізація пропущених операторів ++ та --
Vector& Vector::operator++() {
    for (int i = 0; i < size; i++) num[i]++;
    return *this;
}

Vector Vector::operator++(int) {
    Vector temp(*this);
    for (int i = 0; i < size; i++) num[i]++;
    return temp;
}

Vector& Vector::operator--() {
    for (int i = 0; i < size; i++) num[i]--;
    return *this;
}

Vector Vector::operator--(int) {
    Vector temp(*this);
    for (int i = 0; i < size; i++) num[i]--;
    return temp;
}

Vector Vector::operator*(int scalar) const {
    Vector result(size);
    for (int i = 0; i < size; i++) result.num[i] = num[i] * scalar;
    return result;
}

bool operator==(const Vector& v1, const Vector& v2) {
    if (v1.size != v2.size) return false;
    for (int i = 0; i < v1.size; i++) {
        if (v1.num[i] != v2.num[i]) return false;
    }
    return true;
}

bool operator!=(const Vector& v1, const Vector& v2) { return !(v1 == v2); }
bool operator>(const Vector& v1, const Vector& v2) { return v1.norm() > v2.norm(); }
bool operator<(const Vector& v1, const Vector& v2) { return v1.norm() < v2.norm(); }
bool operator>=(const Vector& v1, const Vector& v2) { return v1.norm() >= v2.norm(); }
bool operator<=(const Vector& v1, const Vector& v2) { return v1.norm() <= v2.norm(); }

ostream& operator<<(ostream& out, const Vector& v) {
    out << string(v);
    return out;
}

istream& operator>>(istream& in, Vector& v) {
    int s;
    in >> s;
    v.setSize(s);
    for (int i = 0; i < v.size; i++) in >> v.num[i];
    return in;
}