#ifndef MONEY_H
#define MONEY_H

#include "Array.h"
#include <iostream>
#include <string>

class Money : public Array {
private:
    bool sign;

public:
    Money(bool flag = true, int rubles = 0, int kopeks = 0);
    Money(double money);
    Money(const std::string& money);

    void Add(const Array* other, Array* result) override;
    Money Subtract(const Money& other) const;
    Money Multiply(const Money& other) const;
    Money Multiply(float value) const;
    Money Divide(const Money& other) const;
    Money Divide(float value) const;
    void print() override;

    bool operator>(const Money& other) const;
    bool operator>=(const Money& other) const;
    bool operator==(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator<=(const Money& other) const;

    int to_sum() const;
    float to_sumF() const;

    friend std::ostream& operator<<(std::ostream& os, const Money& other);
    friend std::istream& operator>>(std::istream& is, Money& other);

    static const int max_size = 100;
};

int lenght_v(int rubles);
int lenght_s(const std::string& str);

#endif 
