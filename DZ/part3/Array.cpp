#include "Array.h"
#include <cstring>


Array::Array(int size, double value) : m_size(size) {
    if (size > max_size) throw std::out_of_range("Size exceeds max_size");
    elements = new double[size];
    std::fill(elements, elements + size, value);
}

Array::Array(int size, const double* ptr) : m_size(size) {
    if (size > max_size) throw std::out_of_range("Size exceeds max_size");
    elements = new double[size];
    std::copy(ptr, ptr + size, elements);
}

Array::Array(const Array& other) : m_size(other.m_size) {
    elements = new double[other.m_size];
    std::copy(other.elements, other.elements + other.m_size, elements);
}

Array::Array(Array&& other) noexcept : m_size(other.m_size), elements(other.elements) {
    other.m_size = 0;
    other.elements = nullptr;
}


Array& Array::operator=(const Array& other) {
    if (this == &other) return *this; 

    delete[] elements;

    m_size = other.m_size;
    elements = new double[other.m_size];
    std::copy(other.elements, other.elements + other.m_size, elements);

    return *this;
}


Array& Array::operator=(Array&& other) noexcept {
    if (this == &other) return *this; 

    delete[] elements;

    m_size = other.m_size;
    elements = other.elements;
    other.m_size = 0;
    other.elements = nullptr;

    return *this;
}


Array::~Array() {
    delete[] elements;
}


Array::Array() : m_size(0), elements(nullptr) {}


double Array::operator[](int index) const {
    if (index < 0 || index >= m_size) throw std::out_of_range("Index out of range");
    return elements[index];
}


double& Array::operator[](int index) {
    if (index < 0 || index >= m_size) throw std::out_of_range("Index out of range");
    return elements[index];
}

int Array::get_size() const { 
    return m_size;
}
double Array::get_element(int index) const {
    return elements[index];
}
double* Array::get_elements() const {
    return elements; 
}
void Array::set_size(int size) {
    m_size = size; 
}
void Array::set_elements(double* elems) {
    elements = elems;
}


