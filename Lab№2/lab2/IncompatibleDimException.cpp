#include "IncompatibleDimException.h"

IncompatibleDimException::IncompatibleDimException(int size1, int size2) {
	m_msg.assign(" ERROR : Incompatible dimention exceptione.\n SIZE_1 = " + std::to_string(size1) + ", SIZE_2 = " + std::to_string(size2));
}
const char* IncompatibleDimException::what() const {
	return m_msg.c_str();
}