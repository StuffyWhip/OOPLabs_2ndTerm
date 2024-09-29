#include <iostream>
#include <iomanip>
#include "SortArray.h"

void SortArray::Add(const Array& other) {
    int currentSize = get_size();
    int otherSize = other.get_size();
    int maxSize = (currentSize > otherSize) ? currentSize : otherSize;

    double* result = new double[maxSize];

    for (int i = 0; i < maxSize; ++i) {
        if (i < currentSize && i < otherSize) {
            result[i] = get_element(i) + other.get_element(i);
        }
        else if (i < currentSize) {
            result[i] = get_element(i);
        }
        else {
            result[i] = other.get_element(i);
        }
    }

    set_size(maxSize);
    delete[] get_elements();
    set_elements(result);
}

void SortArray::enter() {
    std::cout << "Enter size of SortArray:" << std::endl;
    int size;
    std::cin >> size;
    if (size < 0) {
        throw BadSize("The size of the array must be a positive integer number");
    }
    if (size > max_size) {
        throw BadSize("The size of the array is too large");
    }
    set_size(size);
    set_elements(new double[get_size()]);
    std::cout << "Enter SortArray:" << std::endl;
    for (int i = 0; i < get_size(); ++i) {
        std::cin >> get_elements()[i];
    }
}

void SortArray::print() {
    std::cout << "SortArray:" << std::endl;
    for (int i = 0; i < get_size(); ++i) {
        std::cout << std::fixed << std::setprecision(0) << get_element(i) << ' ';
    }
    std::cout << std::endl;
}

void SortArray::Sort(const double a) {
    if (a == 1) {
        for (int i = 0; i < get_size(); ++i) {
            for (int j = get_size() - 1; j > i; --j) {
                if (get_element(j) < get_element(j - 1)) {
                    std::swap(get_elements()[j], get_elements()[j - 1]);
                }
            }
        }
    }
    else if (a == -1) {
        for (int i = 0; i < get_size(); ++i) {
            for (int j = get_size() - 1; j > i; --j) {
                if (get_element(j) > get_element(j - 1)) {
                    std::swap(get_elements()[j], get_elements()[j - 1]);
                }
            }
        }
    }
    else {
        std::cout << "Error!\n1 - ascending sort\n-1 - descending sort\n" << std::endl;
    }
}
