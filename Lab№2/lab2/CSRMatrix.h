#pragma once
#include "Vector.h"

class CSRMatrix
{
	friend class Vector;

	double* aelem;
	int* jptr;
	int* iptr;

	int i_size;
	int j_size;


public:

	CSRMatrix();
	CSRMatrix(const double* in_aelem, const int* in_jptr, const int* in_iptr, int in_i_size, int in_j_size);
	CSRMatrix(const CSRMatrix& mat);
	~CSRMatrix();

	int show_mat() const;

	double dim_j() const;
	int dim_i() const;
	int not_null() const;

	CSRMatrix& operator=(const CSRMatrix& mat);
	CSRMatrix operator*(double n) const;
	friend CSRMatrix operator*(double n, const CSRMatrix& mat);

	Vector operator*(const Vector& vec);
	friend Vector operator*(const Vector& vec1, const CSRMatrix& mat);

	friend std::ostream& operator<< (std::ostream& p_out, const CSRMatrix& mat);
	friend std::istream& operator>> (std::istream& p_in, CSRMatrix& mat);

};