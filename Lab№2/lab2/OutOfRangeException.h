#pragma once
#include <iostream>
#include <string>

class OutOfRangeException : public std::exception
{
	std::string m_msg;

public:

	OutOfRangeException(int p_cur_ind, int p_cur_size);
	const char* what() const override;
};