#include "Vector.h"
#include "CSRMatrix.h"
#include "OutOfRangeException.h"
#include "IncompatibleDimException.h"


Vector::Vector() : size(0), vec_v(nullptr)
{}

Vector::Vector(int n) : size(n)
{
	vec_v = new double[n];

	for (int i = 0; i < n; i++) {
		vec_v[i] = 0;
	}
}
Vector::Vector(int n, double m) : size(n)
{
	vec_v = new double[n];

	for (int i = 0; i < n; i++) {
		vec_v[i] = m;
	}
}
Vector::Vector(const Vector& vec2) : size(vec2.size)
{
	vec_v = new double[vec2.size];

	for (int i = 0; i < vec2.size; i++) {
		vec_v[i] = vec2.vec_v[i];
	}
}
Vector::Vector(std::initializer_list<double> vec3) : size(vec3.size())
{
	vec_v = new double[size];
	int i = 0;
	for (double value : vec3) {
		vec_v[i] = value;
		++i;
	}
}
Vector::~Vector()
{

	delete[] vec_v;
}

Vector& Vector::operator=(const Vector& vec2)
{
	if (this == &vec2)
		return *this;

	if (size != vec2.size) {
		delete[] vec_v;
		vec_v = new double[vec2.size];
		size = vec2.size;
	}

	for (int i = 0; i < size; i++)
		vec_v[i] = vec2.vec_v[i];
	return *this;
}
Vector& Vector::operator+=(const Vector& vec2)
{
	if (size != vec2.size)
		throw IncompatibleDimException(size, vec2.size);

	for (int i = 0; i < size; i++)
		vec_v[i] += vec2.vec_v[i];

	return *this;

}
Vector& Vector::operator-=(const Vector& vec2)
{
	if (size != vec2.size)
		throw IncompatibleDimException(size, vec2.size);

	for (int i = 0; i < size; i++)
		vec_v[i] -= vec2.vec_v[i];

	return *this;

}

const Vector& Vector::operator+() const
{
	return *this;
}
Vector Vector::operator+(const Vector& vec2) const
{

	if (size == vec2.size) {
		Vector res(*this);

		for (int i = 0; i < size; i++)
			res.vec_v[i] += vec2.vec_v[i];
		return res;
	}
	else {
		throw IncompatibleDimException(size, vec2.size);
	}
}

Vector Vector::operator-() const
{
	Vector res(*this);
	for (int i = 0; i < size; i++)
		res.vec_v[i] = -res.vec_v[i];
	return res;
}
Vector Vector::operator-(const Vector& vec2) const
{

	if (size == vec2.size) {
		Vector res(*this);

		for (int i = 0; i < size; i++)
			res.vec_v[i] -= vec2.vec_v[i];
		return res;
	}
	else {
		throw IncompatibleDimException(size, vec2.size);
	}
}

double Vector::operator*(const Vector& vec2) const
{
	if (size != vec2.size)
		throw IncompatibleDimException(size, vec2.size);

	double res = 0;
	for (int i = 0; i < size; i++)
		res += vec_v[i] * vec2.vec_v[i];
	return res;
}
Vector Vector::operator*(double n) const
{
	Vector res(*this);
	for (int i = 0; i < size; i++)
		res.vec_v[i] *= n;
	return res;
}
Vector operator*(double n, const Vector& vec2)
{
	return vec2 * n;
}

Vector::operator double* ()
{
	return vec_v;
}

double& Vector::operator[](int n)
{
	if (n >= size || n < 0) {
		throw OutOfRangeException(n, size);
	}
	return vec_v[n];
}
const double& Vector::operator[](int n) const
{
	if (n >= size || n < 0) {
		throw OutOfRangeException(n, size);
	}
	return vec_v[n];
}

std::istream& operator>>(std::istream& p_in, Vector& vec)
{
	int n;
	std::cout << "Enter dimention of the vector:" << std::endl;
	std::cin >> n;

	if (vec.size != n) {
		delete[] vec.vec_v;
		vec.size = n;
		vec.vec_v = new double[n];
	}

	std::cout << "Enter " << n << " vector values:" << std::endl;
	for (int i = 0; i < n; i++)
		p_in >> vec.vec_v[i];

	return p_in;
}
std::ostream& operator<< (std::ostream& p_out, const Vector& vec)
{
	p_out << '[' << ' ';
	for (int i = 0; i < vec.size; i++)
		p_out << vec.vec_v[i] << " ";
	p_out << ']';

	return p_out;
}

int Vector::dim() const
{
	return size;
}
double Vector::length() const
{
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += vec_v[i] * vec_v[i];
	return sqrt(sum);
}