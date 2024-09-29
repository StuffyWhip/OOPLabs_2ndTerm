#pragma once
#include "Container.h"

template<typename DataType>
class Vector;

template <typename DataType>
class VectorIterator {
private:
    friend class Vector<DataType>;
    DataType* cur;

public:
    VectorIterator() : cur(nullptr) {}

    explicit VectorIterator(DataType* vec, unsigned idx = 0) : cur(vec + idx) {}


    VectorIterator& operator++() {
        if (cur == nullptr) {
            throw std::runtime_error("Incrementing a null iterator");
        }
        ++cur;
        return *this;
    }

    VectorIterator operator++(int p) {
        if (cur == nullptr) {
            throw std::runtime_error("Incrementing a null iterator");
        }
        VectorIterator returned = *this;
        ++cur;
        return returned;
    }

    VectorIterator& operator--() {
        if (cur == nullptr) {
            throw std::runtime_error("Decrementing a null iterator");
        }
        --cur;
        return *this;
    }

    VectorIterator operator--(int p) {
        if (cur == nullptr) {
            throw std::runtime_error("Decrementing a null iterator");
        }
        VectorIterator returned = *this;
        --cur;
        return returned;
    }

    DataType& operator*() {
        if (cur == nullptr) {
            throw std::runtime_error("Dereferencing a null iterator");
        }
        return *cur;
    }


    VectorIterator& operator=(DataType* ptr) {
        if (cur != ptr) {
            cur = ptr;
        }
        return *this;
    }

    VectorIterator operator+(unsigned idx) {
        VectorIterator res = *this;
        res.cur += idx;
        return res;
    }

    VectorIterator operator-(unsigned idx) {
        VectorIterator res = *this;
        res.cur -= idx;
        return res;
    }

    int operator-(const VectorIterator& p) {
        return cur - p.cur;
    }

    bool operator==(const VectorIterator& otherIt) {
        return cur == otherIt.cur;
    }

    bool operator!=(const VectorIterator& otherIt) {
        return cur != otherIt.cur;
    }

    bool operator<(const VectorIterator& otherIt) {
        return cur < otherIt.cur;
    }

    bool operator<(const DataType* ptr) {
        return cur < ptr;
    }

    bool operator<=(const VectorIterator& otherIt) {
        return cur <= otherIt.cur;
    }

    bool operator>(const VectorIterator& otherIt) {
        return cur > otherIt.cur;
    }

    bool operator>=(const VectorIterator& otherIt) {
        return cur >= otherIt.cur;
    }

    VectorIterator& operator+=(int idx) {
        cur += idx;
        return *this;
    }

    VectorIterator& operator-=(int idx) {
        cur -= idx;
        return *this;
    }

    template <typename _IterType>
    explicit operator _IterType* () const {
        return cur;
    }

    DataType* operator->() {
        return cur;
    }

    bool isNull() const {
        return cur == nullptr;
    }
};

