#include "Vector.h"
#include "CSRMatrix.h"
#include "IncompatibleDimException.h"


CSRMatrix::CSRMatrix() : aelem(nullptr), jptr(nullptr), iptr(nullptr), i_size(0), j_size(0)
{}
CSRMatrix::CSRMatrix(const double* in_aelem, const int* in_jptr, const int* in_iptr, int in_i_size, int in_j_size)
{
	i_size = in_i_size;
	j_size = in_j_size;

	aelem = new double[in_j_size];
	jptr = new int[in_j_size];

	for (int i = 0; i < in_j_size; i++) {
		aelem[i] = in_aelem[i];
		jptr[i] = in_jptr[i];
	}

	iptr = new int[in_i_size];
	for (int i = 0; i < in_i_size; i++)
		iptr[i] = in_iptr[i];
}

CSRMatrix::~CSRMatrix()
{
	delete[] aelem;
	delete[] iptr;
	delete[] jptr;
}
CSRMatrix::CSRMatrix(const CSRMatrix& mat)
{
	aelem = new double[mat.j_size];
	jptr = new int[mat.j_size];
	iptr = new int[mat.i_size];

	i_size = mat.i_size;
	j_size = mat.j_size;

	for (int i = 0; i < j_size; i++) {
		aelem[i] = mat.aelem[i];
		jptr[i] = mat.jptr[i];
	}
	for (int i = 0; i < i_size; i++) {
		iptr[i] = mat.iptr[i];
	}

}
CSRMatrix& CSRMatrix::operator=(const CSRMatrix& mat)
{
	if (this == &mat)
		return *this;

	aelem = new double[mat.j_size];
	jptr = new int[mat.j_size];
	iptr = new int[mat.i_size];

	i_size = mat.i_size;
	j_size = mat.j_size;

	for (int i = 0; i < j_size; i++) {
		aelem[i] = mat.aelem[i];
		jptr[i] = mat.jptr[i];
	}
	for (int i = 0; i < i_size; i++) {
		iptr[i] = mat.iptr[i];
	}

	return *this;
}


std::ostream& operator<< (std::ostream& p_out, const CSRMatrix& mat)
{
	int cntr = 0;

	p_out << "Matrix" << std::endl;

	for (int i = 0; i < mat.dim_i(); i++)
	{
		for (int j = 1; j <= mat.dim_j(); j++)
		{
			if (j == mat.jptr[cntr] && cntr + 1 < mat.iptr[i + 1])
			{
				printf("%4.lf |", mat.aelem[cntr]);
				cntr++;
			}
			else
			{
				std::cout << "   0 |";
			}
		}   std::cout << std::endl;
	}

	return p_out;
}


std::istream& operator>> (std::istream& p_in, CSRMatrix& mat)
{
	int n;
	std::cout << "aelem massive:" << std::endl;
	std::cout << "Enter dimention of the vector:" << std::endl;
	std::cin >> n;

	delete[] mat.aelem;
	delete[] mat.jptr;
	delete[] mat.iptr;

	if (n != mat.j_size) {
		mat.j_size = n;

		mat.aelem = new double[mat.j_size];
		mat.jptr = new int[mat.j_size];
	}

	std::cout << "Enter vector values:" << std::endl;
	for (int i = 0; i < mat.j_size; i++)
		p_in >> mat.aelem[i];

	std::cout << "jptr massive:" << std::endl;
	std::cout << "Enter vector values:" << std::endl;
	for (int i = 0; i < mat.j_size; i++)
		p_in >> mat.jptr[i];

	std::cout << "iptr massive:" << std::endl;
	std::cout << "Enter dimention of the vector:" << std::endl;
	std::cin >> n;

	if (n != mat.i_size) {
		mat.i_size = n;
		mat.iptr = new int[mat.i_size];
	}

	std::cout << "Enter vector values:" << std::endl;
	for (int i = 0; i < mat.i_size; i++)
		p_in >> mat.iptr[i];

	return p_in;
}

CSRMatrix CSRMatrix::operator*(double n) const
{
	CSRMatrix res(*this);
	for (int i = 0; i < j_size; i++)
		aelem[i] *= n;

	return res;
}

Vector CSRMatrix::operator*(const Vector& vec)
{

	if (vec.dim() != dim_j())
		throw IncompatibleDimException(vec.dim(), dim_j());

	Vector res(vec.dim());

	for (int i = 0; i < dim_j(); i++)
	{
		for (int j = iptr[i] - 1; j < iptr[i + 1] - 1; j++) {
			res[i] = res[i] + vec[jptr[j] - 1] * aelem[j];
		}
	}
	return res;
}

CSRMatrix operator*(const double n, const CSRMatrix& mat)
{
	return mat * n;
}
Vector operator*(const Vector& vec1, const CSRMatrix& mat)
{
	if (vec1.dim() != mat.dim_i())
		throw IncompatibleDimException(vec1.dim(), mat.dim_i());

	Vector res(vec1.dim());

	for (int i = 0; i < vec1.dim(); i++)
	{
		for (int j = 0; j < mat.not_null(); j++) {
			if (mat.jptr[j] - 1 == i)
			{
				res[i] = res[i] + mat.aelem[j] * vec1[i];
			}
		}
	}

	return res;
}

int CSRMatrix::show_mat() const
{
	int cntr = 0, icntr = 0;
	int m = 0;

	m =dim_j();
	std::cout << "Matrix" << std::endl;

	for (int i = 0; i < i_size - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j + 1 == jptr[cntr])
			{
				printf("%4.lf |", aelem[cntr]);
				cntr++;
			}
			else
			{
				std::cout << "   0 |";
			}
		}   std::cout << std::endl;
	}
	return 0;
}
double CSRMatrix::dim_j() const
{
	double m = 0;
	for (int i = 0; i < j_size; i++)
	{
		if (m < jptr[i])
			m = jptr[i];
	}
	return m;
}
int CSRMatrix::not_null() const
{
	return j_size;
}
int CSRMatrix::dim_i() const
{
	return i_size - 1;
}
