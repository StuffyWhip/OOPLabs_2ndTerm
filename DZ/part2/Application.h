#pragma once
#include "Array.h"
#include "Money.h"
#include "Exceptions.h"
#include "String.h"

class Application {
private:
	int operation;
	Array* base1;
	Array* base2;
	Array* result;
public:
	Application();
	void run();
	void Money_run();
	void String_run();
};
