#pragma once
#include "Exceptions.h"
#include <iostream>

class Array {

public:
	explicit Array(int size, int value = 0);
	explicit Array(int size, const unsigned char* ptr);
	explicit Array(const std::string&);
	Array(const Array& other);
	Array();
	virtual ~Array();

	unsigned char& operator[](const int& index);
	unsigned char operator[](const int& index) const;
	Array& operator=(const Array& other);//Оператор присваивания

	virtual void Add(const Array* other, Array* result);
	virtual void print();
	friend std::istream& operator>>(std::istream& is, Array& other);
	friend std::ostream& operator<<(std::ostream& os, const Array& other);
	static const int max_size = 100;

	unsigned char* getArray() const;
	void setArray(unsigned char* arr);
	int get_size() const;
	void add_size(int);
	void set_size(int);
private:
	unsigned char* array;
	int m_size;

};
