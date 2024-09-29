#include <iostream>
using namespace std;

#define STATIC_LIB 1
#define IMPLICIT_DYNAMIC_LIB 2
#define EXPLICIT_DYNAMIC_LIB 3

#define LIB_TYPE 1
#if (LIB_TYPE == 1)

#include "StaticLib.h"

int main() {
	srand(time(nullptr));
	int n;
	cout << "running programm using static lib\n";
	cout << "Enter N: ";
	cin >> n;
	cout << "\nInputed array: " << endl;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 - 50;
		printf("%4d", a[i]);
	}
	func::BubbleSort(a, n);
	cout << "\nSorted array: " << endl;
	for (int i = 0; i < n; i++)
		printf("%4d", a[i]);
	delete[] a;
}

#elif (LIB_TYPE == 2) //неявное связывание 
#include "DynamicLib.h"
int main() {
	srand(time(nullptr));
	int n;
	cout << "running programm using implict dynamic lib\n";
	cout << "Enter N: ";
	cin >> n;
	cout << "\nInputed array: " << endl;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 - 50;
		printf("%4d", a[i]);
	}
	func::BubbleSort(a, n);
	cout << "\nSorted array: " << endl;
	for (int i = 0; i < n; i++)
		printf("%4d", a[i]);
	delete[] a;
}
#elif (LIB_TYPE == 3) //явное связывание
#include <Windows.h>

int main() {
	srand(time(nullptr));
	int n;
	cout << "running programm using explict dynamic lib\n";
	cout << "Enter N: ";
	cin >> n;
	cout << "\nInputed array: " << endl;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100 - 50;
		printf("%4d", a[i]);
	}
	typedef void(*FuncType) (int[], int);
	FuncType BubbleSort;
	HINSTANCE hdll = LoadLibrary(L"DynamicLib.dll");
	if (nullptr == hdll) {
		cout << "Не удается загрузить Dll." << std::endl;
	}
	else {
		FARPROC ptr = GetProcAddress(hdll, "BubbleSort");

		if (nullptr == ptr)
			cout << "Не удается найти точку входа." << endl;
		else {
			BubbleSort = (FuncType)ptr;
			BubbleSort(a, n);
			cout << "\nSorted array: " << endl;
			for (int i = 0; i < n; i++)
				printf("%4d", a[i]);
		}
		FreeLibrary(hdll);
	}
	delete[] a;
}
#endif