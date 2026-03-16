#pragma once
#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

class Vector
{
private: 
	int num[MAX_SIZE];
	int size;
public:
	Vector();
	Vector(int s, const int* arr);
	Vector(const Vector& other);
	~Vector() {};

	int getSize() const { return size; }
	int getElement(int index) const;

	void setSize(int s);
	void setElement(int index, int value);

	operator string() const;
	Vector& operator = (const Vector&);
	int& operator [] (int index);
 
	double norm() const;
	Vector operator * (int scalar) const;

	friend bool operator == (const Vector& v1, const Vector& v2);
	friend bool operator != (const Vector& v1, const Vector& v2);
	friend bool operator > (const Vector& v1, const Vector& v2);
	friend bool operator < (const Vector& v1, const Vector& v2);
	friend bool operator >= (const Vector& v1, const Vector& v2);
	friend bool operator <= (const Vector& v1, const Vector& v2);

	friend ostream& operator << (ostream& out, const Vector& v);
	friend istream& operator >> (istream& in, Vector& v);
 };

