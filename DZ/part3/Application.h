#pragma once
#include "Array.h"
#include "XorArray.h"
#include "SortArray.h"
#include "Exception.h"

class Application {
private:
	int operation;
	Array* base1;
	Array* base2;
	Array* result;
public:
	Application();
	void run();
	void XorArray_run();
	void SortArray_run();
};