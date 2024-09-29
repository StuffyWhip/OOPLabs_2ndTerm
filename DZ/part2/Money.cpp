#include "Money.h"
#include <sstream>
#include <cmath>

Money::Money(bool flag, int rubles, int kopeks) : Array(2 + lenght_v(rubles)), sign(flag) {
    (*this)[0] = kopeks % 10;
    (*this)[1] = kopeks / 10;
    int len = lenght_v(rubles);
    for (int i = 0; i < len; i++) {
        (*this)[i + 2] = rubles % 10;
        rubles /= 10;
    }
}

Money::Money(double money) : Array(lenght_v((int)money) + 2) {
    std::ostringstream buf;
    buf << money;
    std::string buffer = buf.str();
    int index = (int)buffer.find('.');
    std::string temp;
    temp.assign(buffer, index + 1, 2);
    (*this)[0] = temp[1] - '0';
    (*this)[1] = temp[0] - '0';
    int k = 1;
    if (buffer[0] != '-') {
        sign = true;
        for (int i = index - 1; i >= 0; i--) {
            (*this)[++k] = buffer[i] - '0';
        }
    }
    else {
        sign = false;
        for (int i = index - 1; i >= 1; i--) {
            (*this)[++k] = buffer[i] - '0';
        }
    }
}

Money::Money(const std::string& money) : Array(lenght_s(money)) {
    int index = (int)money.find(',');
    std::string temp;
    temp.assign(money, index + 1, 2);
    (*this)[0] = temp[1] - '0';
    (*this)[1] = temp[0] - '0';
    int k = 1;
    if (money[0] != '-') {
        sign = true;
        for (int i = index - 1; i >= 0; i--) {
            (*this)[++k] = money[i] - '0';
        }
    }
    else {
        sign = false;
        for (int i = index - 1; i >= 1; i--) {
            (*this)[++k] = money[i] - '0';
        }
    }
    for (int i = 0; i < (*this).get_size(); i++) {
        if (strchr("1234567890", (*this)[i] + '0') == nullptr) {
            throw std::exception();
        }
    }
}

void Money::Add(const Array* other, Array* result) {
    const auto* other_1 = dynamic_cast<const Money*>(other);
    if (other_1 == nullptr) {
        throw CastError("MoneySum #1");
    }
    auto* result_1 = dynamic_cast<Money*>(result);
    if (result_1 == nullptr) {
        throw CastError("MoneySum #2");
    }
    int sumInKopeks = to_sum() + other_1->to_sum();
    int rubles = sumInKopeks / 100; 
    int kopeks = sumInKopeks % 100; 
    *result_1 = Money(sign, rubles, kopeks); 
}


Money Money::Subtract(const Money& other) const {

    int differenceInKopeks = to_sum() - other.to_sum();

    int rubles = differenceInKopeks / 100;
    int kopeks = std::abs(differenceInKopeks) % 100; 
    
    return Money(sign, rubles, kopeks);
}


Money Money::Multiply(const Money& other) const {
    int this_sum = to_sum(); 
    int other_sum = other.to_sum();
    long long result_sum = static_cast<long long>(this_sum) * other_sum / 100; 
    return Money(static_cast<float>(result_sum) / 100); 
}

Money Money::Multiply(float value) const {
    if (value == 0) {
        throw MathException("Multiply number");
    }
    int this_sum = to_sum();
    long long result_sum = static_cast<long long>(round(this_sum * value)); 
    return Money(static_cast<float>(result_sum) / 100);
}

Money Money::Divide(const Money& other) const {
    if (other.to_sum() == 0) {
        throw MathException("Divide");
    }
    int this_sum = to_sum(); 
    int other_sum = other.to_sum(); 
    long long result_sum = (static_cast<long long>(this_sum) * 100) / other_sum; 
    return Money(static_cast<float>(result_sum) / 100); 
}

Money Money::Divide(float value) const {
    if (value == 0) {
        throw MathException("Divide number");
    }
    int this_sum = to_sum();
    long long result_sum = static_cast<long long>(round(this_sum / value)); 
    return Money(static_cast<float>(result_sum) / 100);
}

void Money::print() {
    std::cout << *this << std::endl;
}

int lenght_v(int rubles) {
    int len = 0;
    while (rubles != 0) {
        rubles /= 10;
        len++;
    }
    return len;
}

bool Money::operator>(const Money& other) const {
    return to_sum() > other.to_sum();
}

bool Money::operator>=(const Money& other) const {
    return *this > other || *this == other;
}

bool Money::operator==(const Money& other) const {
    return to_sum() == other.to_sum();
}

bool Money::operator<(const Money& other) const {
    return !(*this > other) && !(*this == other);
}

bool Money::operator<=(const Money& other) const {
    return !(*this > other);
}

int lenght_s(const std::string& str) {
    if (str[0] == '-') {
        return (int)str.length() - 2;
    }
    return (int)str.length() - 1;
}

int Money::to_sum() const {
    int sum = 0;
    int p = 1;
    for (int i = 0; i < get_size(); i++) {
        sum += (*this)[i] * p;
        p *= 10;
    }
    if (!sign) {
        sum *= -1;
    }
    return sum;
}

std::ostream& operator<<(std::ostream& os, const Money& other) {
    if (!other.sign) {
        os << '-';
    }
    bool g = true;
    for (int i = other.get_size() - 1; i > 1; i--) {
        os << (int)other[i];
        if (other[i] != 0) {
            g = false;
        }
    }
    if (g) {
        os << "0";
    }
    os << "," << (int)other[1] << (int)other[0];
    return os;
}

std::istream& operator>>(std::istream& is, Money& other) {
    std::cout << "Enter the amount: rubles,kopecks" << std::endl;
    std::string money;
    is >> money;
    int index = (int)money.find(',');
    std::string temp;
    temp.assign(money, index + 1, 2);
    other.set_size(lenght_s(money));
    if (other.get_size() > Money::max_size) {
        throw OutOfRange("Fraction std::cin");
    }
    delete[] other.getArray();
    other.setArray(new unsigned char[other.get_size()]);
    other[0] = temp[1] - '0';
    other[1] = temp[0] - '0';
    int k = 1;
    if (money[0] == '-') {
        other.sign = false;
        for (int i = index - 1; i > 0; i--) {
            other[++k] = money[i] - '0';
        }
    }
    else {
        for (int i = index - 1; i >= 0; i--) {
            other[++k] = money[i] - '0';
        }
    }
    for (int i = 0; i < other.get_size(); i++) {
        if (strchr("1234567890", other[i] + '0') == nullptr) {
            delete[] other.getArray();
            throw std::exception();
        }
    }
    return is;
}

float Money::to_sumF() const {
    return static_cast<float>(to_sum()) / 100;
}