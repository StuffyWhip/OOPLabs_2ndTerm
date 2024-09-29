#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include "LongLong.h"

class Money {
public:
    Money();
    Money(const LongLong& newnum);
    static unsigned int count;

    void add(const Money& money1, const Money& money2);
    void sub(const Money& money1, const Money& money2);
    double del(const Money& money1, const Money& money2);

    friend std::istream& operator>>(std::istream& in, Money& money);
    friend std::ostream& operator<<(std::ostream& out, const Money& money);

    Money operator*(double data) const;
    Money operator/(double data) const;

    bool operator==(const Money& sum) const;
    bool operator>(const Money& sum) const;
    bool operator<(const Money& sum) const;

private:
    LongLong num;
};

#endif
