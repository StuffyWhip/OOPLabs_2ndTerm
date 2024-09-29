#ifndef LONGLONG_H
#define LONGLONG_H

class LongLong {
public:
    LongLong(int senior = 0, unsigned int junior = 0, unsigned int max = 100)
        : seniorPart(senior), juniorPart(junior), maxValue(max) {}

    LongLong operator+(const LongLong& other) const;
    LongLong operator-(const LongLong& other) const;
    LongLong operator*(double data) const;
    LongLong operator/(double data) const;

    bool operator==(const LongLong& other) const;
    bool operator>(const LongLong& other) const;
    bool operator<(const LongLong& other) const;

    void ChangeMax(unsigned int newMax) { maxValue = newMax; }

    int ReturnSenior() const { return seniorPart; }
    unsigned int ReturnJunior() const { return juniorPart; }
    unsigned int ReturnMax() const { return maxValue; }

private:
    int seniorPart;
    unsigned int juniorPart;
    unsigned int maxValue;
};

#endif
