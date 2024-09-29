#pragma once
#include <iostream>


class Vector
{
	friend class CSRMatrix;
	friend class OutOfRangeException;

	double* vec_v;
	int size;

public:

	Vector();
	Vector(int n, double m);
	explicit Vector(int n);
	Vector(const Vector& vec2);
	Vector(std::initializer_list<double> vec3);
	~Vector();

	double length() const;
	int dim() const;

	const Vector& operator+() const;
	Vector operator+(const Vector& vec2) const;

	Vector operator-() const;
	Vector operator-(const Vector& vec2) const;

	double operator*(const Vector& vec2) const;
	Vector operator*(double n) const;

	friend Vector operator*(double n, const Vector& vec2);
	friend Vector operator*(const Vector& vec1, const CSRMatrix& mat);


	explicit operator double* ();
	const double& operator[](int n) const;
	double& operator[](int n);


	Vector& operator=(const Vector& vec2);
	Vector& operator+=(const Vector& vec2);
	Vector& operator-=(const Vector& vec2);


	friend std::istream& operator>>(std::istream& p_in, Vector& vec);
	friend std::ostream& operator<<(std::ostream& p_out, const Vector& vec);
	friend std::istream& operator>>(std::istream& p_out, CSRMatrix& mat);

};
