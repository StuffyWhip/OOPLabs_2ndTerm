#include "Exceptions.h"

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


StringException::StringException(const std::string& error) {
	errorMsg = "Error occured while operating with strings: " + error;
}

const char* StringException::what() const noexcept {
	return errorMsg.c_str();
}

CastError::CastError(const std::string& error) {
	errorMsg = "Error occured while casting " + error;
}

const char* CastError::what() const noexcept {
	return errorMsg.c_str();
}
