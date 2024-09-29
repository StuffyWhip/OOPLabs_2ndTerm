#pragma once
#include "Money.h"

class Application {
private:
	Money amount;

public:
	Application();

	explicit Application(const Money& m);
	void menu();
	void run();
};