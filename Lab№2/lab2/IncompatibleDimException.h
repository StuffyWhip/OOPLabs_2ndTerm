#pragma once
#include <iostream>
#include <string>

class IncompatibleDimException : public std::exception
{
	std::string m_msg;

public:

	IncompatibleDimException(int size1, int size2);
	const char* what() const override;
};