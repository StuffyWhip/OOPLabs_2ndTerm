#include "Exception.h"

OutOfRange::OutOfRange(const std::string& error) {
	errorMsg = "Error: out of range exception at operation (" + error + ")";
}

const char* OutOfRange::what() const noexcept {
	return errorMsg.c_str();
}

BadSize::BadSize(const std::string& error) {
	errorMsg = "Error: incorrect size of object at operation (" + error + ")";
}

const char* BadSize::what() const noexcept {
	return errorMsg.c_str();
}

MathException::MathException(const std::string& error) {
	errorMsg = "Error: a Math exception occured when operating with objects: " + error;
}

const char* MathException::what() const noexcept {
	return errorMsg.c_str();
}
