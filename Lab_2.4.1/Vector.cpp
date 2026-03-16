#include "Vector.h"
#include <sstream>
#include <cmath>

Vector::Vector() : size(0)
{
	for (int i = 0; i < MAX_SIZE; i++)
		num[i] = 0;
}

Vector::Vector(int s, const int* arr)
{
	setSize(s);
	for (int i = 0; i < size; i++)
		num[i] = arr[i];

	for (int i = size; i < MAX_SIZE; i++)
		num[i] = 0;
}

Vector::Vector(const Vector& other) : size(other.size)
{
	for (int i = 0; i < size; i++)
		num[i] = other.num[i];
}

void Vector::setSize(int s)
{
	if (s >= 0 && s <= MAX_SIZE)
		size = s;
	else
	{
		cerr << "Error: Invalid size" << endl;
		size = 0;
	}
}

int Vector::getElement(int index) const
{
	if (index >= 0 && index < size)
		return num[index];
	else
	{
		cerr << "Error: Index out of bounds" << endl;
		return 0;
	}
}

void Vector::setElement(int index, int value)
{
	if (index >= 0 && index < size)
		num[index] = value;
	else
		cerr << "Error: Index out of bounds" << endl;
}

double Vector::norm() const
{
	long sum = 0;
	for (int i = 0; i < size; i++)
		sum += num[i] * num[i];
	return sqrt(static_cast<double>(sum));
}

Vector Vector::operator *(int scalar) const
{
	Vector result(*this);
	for (int i = 0; i < result.size; i++)
		result.num[i] *= scalar;
	return result;
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

Vector& Vector::operator = (const Vector& other) {
	if (this != &other) {
		size = other.size;
		for (int i = 0; i < size; i++) 
			num[i] = other.num[i];	
	}
	return *this;
}

int& Vector::operator [] (int index) {
	if (index >= 0 && index < size) return num[index];
	cerr << "Error: Index out of bounds!" << endl;
	static int dummy = 0;
	return dummy;
}

bool operator == (const Vector& v1, const Vector& v2) {
	if (v1.size != v2.size) return false;
	for (int i = 0; i < v1.size; i++) {
		if (v1.num[i] != v2.num[i]) return false;
	}
	return true;
}

bool operator != (const Vector& v1, const Vector& v2) {
	return !(v1 == v2);
}

bool operator < (const Vector& v1, const Vector& v2) {
	return v1.norm() < v2.norm();
}

bool operator > (const Vector& v1, const Vector& v2) {
	return v1.norm() > v2.norm();
}

bool operator <= (const Vector& v1, const Vector& v2) {
	return v1.norm() <= v2.norm();
}

bool operator >= (const Vector& v1, const Vector& v2) {
	return v1.norm() >= v2.norm();
}

ostream& operator << (ostream& out, const Vector& v) {
	out << string(v);
	return out;
}

istream& operator >> (istream& in, Vector& v) {
	int s;
	cout << "Enter size: "; in >> s;
	v.setSize(s);
	for (int i = 0; i < v.size; i++) {
		cout << "Element [" << i << "]: ";
		in >> v.num[i];
	}
	return in;
}