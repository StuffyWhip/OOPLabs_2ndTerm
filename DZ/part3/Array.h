#pragma once
#include <iostream>
#include "Exception.h"

class Array {

public:
    explicit Array(int size, double value = 0);
    explicit Array(int size, const double* ptr);
    Array(const Array& other);          
    Array(Array&& other) noexcept;      
    Array& operator=(const Array& other); 
    Array& operator=(Array&& other) noexcept; 
    virtual ~Array();                   

    Array();

    virtual void Add(const Array& other) = 0;
    virtual void Sort(const double a) = 0;
    virtual void print() = 0;
    virtual void enter() = 0;
    static const int max_size = 100;
    double operator[](int index) const; 
    double& operator[](int index);      
    int get_size() const;
    double get_element(int index) const;
    double* get_elements() const;
    void set_size(int size);
    void set_elements(double* elems);
private:

    int m_size;
    double* elements;

};
