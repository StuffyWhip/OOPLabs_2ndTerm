#pragma once
#include "Array.h"
#include <valarray>
#include <iomanip>

class XorArray : public Array {
public:
	explicit XorArray(int size) : Array(size) {};
	explicit XorArray(int size, const double* ptr) : Array(size, ptr) {};


	XorArray() = default; 

	void Add(const Array& other) override;
	void Sort(const double a) override;
	void print() override;
	void enter() override;
	XorArray& operator=(const XorArray& other);
};
