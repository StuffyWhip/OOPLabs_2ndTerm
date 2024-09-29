#pragma once
#include <exception>
#include <string>
#include <iostream>

class OutOfRange : public std::exception {
private:
	std::string errorMsg;
public:
	explicit OutOfRange(const std::string& error);
	const char* what() const noexcept override;
};

class BadSize : public std::exception {
private:
	std::string errorMsg;
public:
	explicit BadSize(const std::string& error);
	const char* what() const noexcept override;
};

class MathException : public std::exception
{
private:
	std::string errorMsg;
public:
	explicit MathException(const std::string& error);
	const char* what() const noexcept override;
};
