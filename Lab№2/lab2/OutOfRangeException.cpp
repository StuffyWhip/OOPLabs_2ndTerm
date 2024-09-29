#include "OutOfRangeException.h"
OutOfRangeException::OutOfRangeException(int p_cur_ind, int p_cur_size) {
	m_msg.assign(" ERROR : Array out of range.\n SIZE = " + std::to_string(p_cur_size) + ", INDEX = " + std::to_string(p_cur_ind));
}
const char* OutOfRangeException::what() const {
	return m_msg.c_str();
}