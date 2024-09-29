#include "String.h"

String::String(int size) : Array(size + 1) {
    (*this)[0] = size;
}

String::String(const std::string& str) : Array((int)str.length() + 1) {
    (*this)[0] = get_size() - 1;
    for (int i = 1; i < get_size(); i++) {
        (*this)[i] = str[i - 1];
    }
}

void String::Add(const Array* other, Array* result) {
    if (get_size() + other->get_size() - 1 > max_size) {
        throw StringException("The size of the merge > max size");
    }
    result->set_size(get_size() + other->get_size() - 1);
    for (int i = 1; i < (*this).get_size(); i++) {
        (*result)[i] = (*this)[i];
    }
    for (int i = 0; i < other->get_size() - 1; i++) {
        (*result)[i + get_size()] = (*other)[i + 1];
    }
    (*result)[0] = get_size() + other->get_size() - 1;
}

void String::print() {
    std::cout << "String: " << std::endl;
    for (int i = 1; i < get_size(); i++) {
        std::cout << (*this)[i];
    }
    std::cout << std::endl;
}

String String::Insert(int a, const String& other) {
    if (a < 0 || a >= get_size())
        throw StringException("Position doesnt exist");
    if (str_len() + other.str_len() >= String::max_size)
        throw StringException("The size of the string > max size");
    String s(str_len() + other.str_len());
    for (int i = 1; i <= a; i++) {
        s[i] = (*this)[i];
    }
    for (int i = a + 1; i <= other.str_len() + a; i++) {
        s[i] = other[i - a];
    }
    for (int i = other.str_len() + a + 1; i < s.get_size(); i++) {
        s[i] = (*this)[i - other.str_len()];
    }
    s[0] = get_size() - 1;
    return s;
}

String String::Delete_part_str(const String& other) {
    int k = 0, t = -1;
    if (other.str_len() < 1) {
        throw StringException("Metod Delete_part_str: the string to be deleted must contain at least one character");
    }
    if (get_size() < other.get_size()) {
        throw StringException("Metod Delete_part_str: the string to be deleted must be less that other string");
    }
    for (int i = 1; i <= get_size() - other.str_len(); i++) {
        if ((*this)[i] == other[1]) {
            bool f = true;
            for (int j = i + 1; (j < other.str_len() + i) && f; j++) {
                if ((*this)[j] != other[j - i + 1]) {
                    f = false;
                }
            }
            if (f) {
                t = i;
                k++;
                i += other.str_len() - 1;
            }
        }
    }
    String s(get_size() - k * other.str_len() - 1);
    k = 1;
    for (int i = 1; i <= get_size() - other.str_len(); i++) {
        if ((*this)[i] == other[1]) {
            bool f = true;
            for (int j = i + 1; (j < other.str_len() + i) && f; j++) {
                if ((*this)[j] != other[j - i + 1]) {
                    f = false;
                }
            }
            if (!f) {
                s[k++] = (*this)[i];
            }
            else {
                i += other.str_len() - 1;
            }
        }
        else {
            s[k++] = (*this)[i];
        }
    }
    if (t != -1 && t + other.str_len() >= get_size() - other.str_len()) {
        for (int i = t + other.str_len(); i < get_size(); i++) {
            s[k++] = (*this)[i];
        }
    }
    else {
        for (int i = get_size() - other.str_len() + 1; i < get_size(); i++) {
            s[k++] = (*this)[i];
        }
    }
    return s;
}

int String::Search_part_str(const String& other) {
    if (get_size() < other.get_size()) {
        return -1;
    }
    else if (get_size() == other.get_size()) {
        for (int i = 0; i < get_size(); i++) {
            if ((*this)[i] != other[i])
                return -1;
        }
        return 0;
    }
    else {
        for (int i = 1; i <= get_size() - other.str_len(); i++) {
            if ((*this)[i] == other[1]) {
                bool f = true;
                for (int j = i + 1; (j < other.str_len() + i) && f; j++) {
                    if ((*this)[j] != other[j - i + 1]) {
                        f = false;
                    }
                }
                if (f)
                    return i - 1;
            }
        }
    }
    return -1;
}

int String::str_len() const {
    return (*this)[0];
}

std::ostream& operator<<(std::ostream& os, const String& other) {
    for (int i = 1; i < other.get_size(); i++) {
        os << other[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, String& other) {
    std::string str;
    std::cout << "Input the string:" << std::endl;
    is >> str;
    if (str.length() <= 0) {
        throw BadSize("The size of the string must be a positive integer number");
    }
    if (str.length() >= String::max_size) {
        throw BadSize("The size of the string is too large");
    }
    other.set_size(str.length() + 1);
    delete[] other.getArray();
    other.setArray(new unsigned char[str.length()]);
    other[0] = str.length();
    for (int i = 1; i <= str.length(); i++) {
        other[i] = str[i - 1];
    }
    return is;
}
