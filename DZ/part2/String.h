#pragma once
#include "Array.h"

class String : public Array {
public:
	explicit String(int size);
	explicit String(const std::string& str);
	String() = default;

	void Add(const Array* other, Array* result) override;
	void print() override;
	String Insert(int a, const String& other);
	String Delete_part_str(const String& other);
	int Search_part_str(const String& other);
	friend std::ostream& operator<<(std::ostream& os, const String& other);
	friend std::istream& operator>>(std::istream& is, String& other);

	int str_len() const;
};

