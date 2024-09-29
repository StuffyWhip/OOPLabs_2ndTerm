#include "Money.h"

unsigned int Money::count = 0;

Money::Money()
    : num(0, 0, 100) {
    ++count;
}

Money::Money(const LongLong& newnum) {
    num = newnum;
    num.ChangeMax(100);
    ++count;
}

void Money::add(const Money& money1, const Money& money2) {
    LongLong sum = money1.num + money2.num;
    sum.ChangeMax(100);
    num = sum;
}

void Money::sub(const Money& money1, const Money& money2) {
    LongLong diff = money1.num - money2.num;
    diff.ChangeMax(100);
    num = diff;
}

double Money::del(const Money& money1, const Money& money2) {
    long sin1 = money1.num.ReturnSenior(), sin2 = money2.num.ReturnSenior();
    unsigned long jun1 = money1.num.ReturnJunior(), jun2 = money2.num.ReturnJunior(), sum = money1.num.ReturnMax();
    long long sum1, sum2;
    if (sin1 >= 0)
        sum1 = sin1 * sum + jun1;
    else
        sum1 = sin1 * sum - jun1;
    if (sin2 >= 0)
        sum2 = sin2 * sum + jun2;
    else
        sum2 = sin2 * sum - jun2;
    return static_cast<double>(sum1) / sum2;
}

std::istream& operator>>(std::istream& in, Money& money) {
    int senior, junior;
    std::cout << "Senior part: ";
    in >> senior;
    std::cout << "Junior part: ";
    in >> junior;
    money.num = LongLong(senior, junior, 100);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Money& money) {
    int senior = money.num.ReturnSenior();
    unsigned int junior = money.num.ReturnJunior();
    out << senior << "," << (junior < 10 ? "0" : "") << junior;
    return out;
}

Money Money::operator*(double data) const {
    LongLong result = num * data;
    result.ChangeMax(100);
    return Money(result);
}

Money Money::operator/(double data) const {
    LongLong result = num / data;
    result.ChangeMax(100);
    return Money(result);
}

bool Money::operator==(const Money& sum) const {
    return (num == sum.num);
}

bool Money::operator>(const Money& sum) const {
    return (num > sum.num);
}

bool Money::operator<(const Money& sum) const {
    return (num < sum.num);
}
