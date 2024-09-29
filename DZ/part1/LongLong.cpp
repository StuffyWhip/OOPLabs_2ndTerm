#include "LongLong.h"

LongLong LongLong::operator+(const LongLong& other) const {
    int newSenior = seniorPart + other.seniorPart;
    unsigned int newJunior = juniorPart + other.juniorPart;
    if (newJunior >= maxValue) {
        newSenior += newJunior / maxValue;
        newJunior %= maxValue;
    }
    return LongLong(newSenior, newJunior, maxValue);
}

LongLong LongLong::operator-(const LongLong& other) const {
    int newSenior = seniorPart - other.seniorPart;
    unsigned int newJunior = juniorPart;
    if (juniorPart < other.juniorPart) {
        newSenior--;
        newJunior = (maxValue + juniorPart) - other.juniorPart;
    }
    else {
        newJunior -= other.juniorPart;
    }
    return LongLong(newSenior, newJunior, maxValue);
}

LongLong LongLong::operator*(double data) const {
    long long total = (seniorPart * maxValue + juniorPart) * data;
    int newSenior = total / maxValue;
    unsigned int newJunior = total % maxValue;
    return LongLong(newSenior, newJunior, maxValue);
}

LongLong LongLong::operator/(double data) const {
    long long total = seniorPart * maxValue + juniorPart;
    total /= data;
    int newSenior = total / maxValue;
    unsigned int newJunior = total % maxValue;
    return LongLong(newSenior, newJunior, maxValue);
}

bool LongLong::operator==(const LongLong& other) const {
    return (seniorPart == other.seniorPart && juniorPart == other.juniorPart);
}

bool LongLong::operator>(const LongLong& other) const {
    if (seniorPart > other.seniorPart) return true;
    if (seniorPart == other.seniorPart && juniorPart > other.juniorPart) return true;
    return false;
}

bool LongLong::operator<(const LongLong& other) const {
    if (seniorPart < other.seniorPart) return true;
    if (seniorPart == other.seniorPart && juniorPart < other.juniorPart) return true;
    return false;
}
