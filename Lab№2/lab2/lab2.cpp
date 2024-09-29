#include "Vector.h"
#include "CSRMatrix.h"
#include "IncompatibleDimException.h"
#include "OutOfRangeException.h"
#include <string.h>
#include <iostream>


int main() {

	Vector q;
	Vector p(3);
	Vector n(5, 8);
	Vector t(5, 2);
	Vector n_cpy(n);

	int a = 0;

	std::cout << "Initial values: " << std::endl << std::endl;
	std::cout << "Vector q: " << q << std::endl;
	std::cout << "Vector p: " << p << std::endl;
	std::cout << "Vector n: " << n << std::endl;
	std::cout << "Vector t: " << t << std::endl;
	std::cout << "Vector n_cpy: " << n_cpy << std::endl << std::endl;

	std::cout << "q = p " << std::endl;
	q = p;
	std::cout << "Vector q: " << q << std::endl << std::endl;

	std::cout << "n += t " << std::endl;
	n += t;
	std::cout << "Vector n: " << n << std::endl << std::endl;

	std::cout << "Imputting new vector t:" << std::endl;
	for (int i = 0; i < t.dim(); i++) {
		std::cout << "Imputting value for t[" << i << "] = ";
		std::cin >> a;
		t[i] = a;
	}
	std::cout << std::endl << "Entered Vector t:" << t << std::endl << std::endl;

	std::cout << "n -= t " << std::endl;
	n -= t;
	std::cout << "Vector n: " << n << std::endl << std::endl;

	q = n + n;
	std::cout << "n + n = " << q << std::endl << std::endl;

	q = n - t;
	std::cout << "n - t = " << q << std::endl << std::endl;

	q = t * 2;
	std::cout << "t * 2 = " << q << std::endl << std::endl;

	q = 2 * t;
	std::cout << "2 * t = " << q << std::endl << std::endl;

	a = n * t;
	std::cout << "n * t = " << a << std::endl << std::endl;

	std::cout << "t.dim() = " << t.dim() << std::endl;
	std::cout << "t.length() = " << t.length() << std::endl << std::endl;

	double arr1[25] = { 9, 3, 1, 1, 11, 2, 1, 2, 1, 10, 2, 2, 1, 2, 9, 1, 1, 1, 12, 1, 8, 2, 2, 3, 8 };
	int arr2[25] = { 1, 4, 5, 7, 2, 3, 4, 7, 2, 3, 4, 1,2, 3, 4, 5, 1, 4, 5, 7, 6, 1, 2, 5, 7 };
	int arr3[8] = { 1, 5, 9, 12, 17, 21, 22, 26 };

	Vector aelem(25), jptr(25), iptr(8), arr(7, 2);

	for (int i = 0; i < 25; i++) {
		aelem[i] = arr1[i];
		jptr[i] = arr2[i];
	}
	for (int i = 0; i < 8; i++)
		iptr[i] = arr3[i];

	CSRMatrix A(arr1, arr2, arr3, iptr.dim(), aelem.dim());
	CSRMatrix A_cpy(A);
	CSRMatrix A_equal;
	CSRMatrix A_in;

	std::cout << "Initial values for matrix: " << std::endl << std::endl;
	std::cout << "A" << std::endl << A << std::endl;
	std::cout << "A_cpy(A)" << std::endl << A_cpy << std::endl;
	A_equal = A;
	std::cout << "A_equal = A" << std::endl << A_equal << std::endl;


	std::cout << "Matrix * vector = " << A * arr << std::endl << std::endl;
	std::cout << "Vector * Matrix = " << arr * A << std::endl << std::endl;
	std::cout << "Matrix * Vector = " << A * arr << std::endl << std::endl;

	std::cin >> A_in;
	std::cout << "Inputed Matrix: " << std::endl << A_in;

	Vector rs(7, 1), v1(7, 1), v2(7, 2), v3(7, 3);


	rs = -5 * A * (v1 - 3 * v2) + v3 * 6;
	std::cout << " -5 * A * (v1 - 3 * v2) + v3 * 6 = " << rs << std::endl << std::endl;

	std::cout << "try n[6] (OutOfRangeException)" << std::endl;
	try {
		std::cout << n[6] << std::endl << std::endl;
	}
	catch (const OutOfRangeException& e) {
		std::cerr << e.what() << std::endl << std::endl;;
	}
	std::cout << "try n + arr (IncompatibleDimException)" << std::endl;
	try {
		std::cout << n + arr << std::endl << std::endl;
	}
	catch (const IncompatibleDimException& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	std::cout << "Extra exercise:" << std::endl;
	Vector list = { 5, 6, 7 };
	std::cout << "Vector v3 values: " << list << std::endl;

	return 0;
};