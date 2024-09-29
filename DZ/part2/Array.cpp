#include "Array.h"

Array::Array(int size, int value) {
    if (size > max_size) {
        throw BadSize("The size of the array is too large");
    }
    if (size < 0) {
        throw BadSize("The size of the array must be a positive integer number");
    }
    m_size = size;
    array = new unsigned char[size];
    for (int i = 0; i < size; i++) {
        array[i] = value;
    }
}

Array::Array(const Array& other) {
    m_size = other.m_size;
    if (m_size == 0) {
        array = nullptr;
    }
    else {
        array = new unsigned char[m_size];
        for (int i = 0; i < m_size; i++) {
            array[i] = other[i];
        }
    }
}

Array::Array(const std::string& str) {
    m_size = (int)str.length();
    array = new unsigned char[m_size];
    for (int i = 0; i < m_size; i++) {
        array[i] = str[i];
    }
}

Array::Array() : m_size(0), array(nullptr) {}

Array::~Array() {
    delete[] array;
}

Array::Array(int size, const unsigned char* ptr) {
    if (size > max_size) {
        throw BadSize("The size of the array is too large");
    }
    if (size < 0) {
        throw BadSize("The size of the array must be a positive integer number");
    }
    m_size = size;
    array = new unsigned char[size];
    for (int i = 0; i < size; i++) {
        array[i] = ptr[i];
    }
}

unsigned char& Array::operator[](const int& index) {
    if (index >= m_size || index < 0)
        throw OutOfRange("Array::operator[]");
    return array[index];
}

unsigned char Array::operator[](const int& index) const {
    if (index >= m_size || index < 0)
        throw OutOfRange("Array::operator[]");
    return array[index];
}

Array& Array::operator=(const Array& other) {
    if (this == &other) {
        return *this;
    }
    if (m_size != other.m_size) {
        delete[] array;
        array = new unsigned char[other.m_size];
        m_size = other.m_size;
    }
    for (int i = 0; i < m_size; i++) {
        array[i] = other[i];
    }
    return *this;
}

void Array::print() {
    std::cout << "Array:" << std::endl;
    for (int i = 0; i < m_size; i++) {
        std::cout << (int)array[i] << ' ';
    }
    std::cout << std::endl;
}

void Array::Add(const Array* other, Array* result) {
    if (array == nullptr || other->array == nullptr) {
        throw OutOfRange("method Array::Add");
    }
    if (m_size > other->m_size) {
        result->m_size = m_size;
        delete[] result->array;
        result->array = new unsigned char[m_size];
        for (int i = 0; i < m_size; i++) {
            (*result)[i] = array[i];
        }
        for (int i = 0; i < other->m_size; i++) {
            (*result)[i] += (*other)[i];
        }
    }
    else if (m_size < other->m_size) {
        result->m_size = other->m_size;
        delete[] result->array;
        result->array = new unsigned char[other->m_size];
        for (int i = 0; i < other->m_size; i++) {
            (*result)[i] = (*other)[i];
        }
        for (int i = 0; i < m_size; i++) {
            (*result)[i] += array[i];
        }
    }
    else {
        result->m_size = m_size;
        for (int i = 0; i < m_size; i++) {
            (*result)[i] = (*other)[i] + array[i];
        }
    }
}

std::istream& operator>>(std::istream& is, Array& other) {
    int size;
    std::cout << "Input size of Array:" << std::endl;
    is >> size;
    if (size > Array::max_size) {
        throw BadSize("The size of the array is too large");
    }
    if (size < 0) {
        throw BadSize("The size of the array must be a positive integer number");
    }
    other.m_size = size;
    delete[] other.array;
    std::cout << "Input Array:" << std::endl;
    other.array = new unsigned char[other.m_size];
    for (int i = 0; i < other.m_size; i++) {
        is >> size;
        other[i] = size;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Array& other) {
    std::cout << "Array:" << std::endl;
    for (int i = 0; i < other.m_size; i++) {
        os << (int)other.array[i] << ' ';
    }
    std::cout << std::endl;
    return os;
}

void Array::add_size(int value) {
    if (m_size + value > max_size) {
        throw BadSize("The size of the array is too large");
    }
    if (m_size + value < 0) {
        throw BadSize("The size of the array must be a positive integer number");
    }
    m_size += value;
}

int Array::get_size() const {
    return m_size;
}

void Array::set_size(int k) {
    m_size = k;
    delete[] array;
    array = new unsigned char[k];
}
unsigned char* Array::getArray() const {
    return array; 
}
void Array::setArray(unsigned char* arr) { 
    array = arr;
}