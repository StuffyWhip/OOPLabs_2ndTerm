#include <stdexcept>
#include <string>

class OutOfRangeException : public std::runtime_error {
public:
    OutOfRangeException(int index)
        : std::runtime_error("Index out of range: " + std::to_string(index)) {}
};