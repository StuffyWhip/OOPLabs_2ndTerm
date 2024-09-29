#include "XorArray.h"

void XorArray::enter() {
    std::cout << "Enter size of XorArray:" << std::endl;
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
    std::cout << "Enter XorArray:" << std::endl;
    for (int i = 0; i < get_size(); ++i) {
        std::cin >> get_elements()[i];
    }
}

void XorArray::print() {
    std::cout << "XorArray:" << std::endl;
    for (int i = 0; i < get_size(); ++i) {
        std::cout << std::fixed << std::setprecision(1) << get_element(i) << ' ';
    }
    std::cout << std::endl;
}

void XorArray::Add(const Array& other) {
    int currentSize = get_size();
    int otherSize = other.get_size();
    double* mas = new double[otherSize]; 
    for (int i = 0; i < otherSize; ++i) {
        mas[i] = 0; 
    }
    
    for (int i = 0; i < currentSize; ++i) {
        mas[i] = get_element(i);
    }
    if (currentSize >= otherSize) {
        
        for (int i = 0; i < otherSize; ++i) {
            mas[i] += other.get_element(i);
        }
    }
    else {

        delete[] get_elements();
        set_elements(new double[otherSize]);
        for (int i = 0; i < otherSize; ++i) {
            get_elements()[i] = mas[i];
        }

        for (int i = 0; i < otherSize; ++i) {
            get_elements()[i] += other.get_element(i);
        }
        set_size(otherSize);
    }
    delete[] mas;
}


void XorArray::Sort(const double a) {
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
