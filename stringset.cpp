#include "stringset.h"
#include <cstring>

StringSet::StringSet() : str(nullptr), length(0) {}

StringSet::StringSet(const char* s) : str(nullptr), length(0) {
    if (s) {
        length = static_cast<int>(strlen(s));
        str = new char[length + 1];
        strcpy_s(str, length + 1, s);  
    }
}

StringSet::StringSet(const StringSet& other) : str(nullptr), length(other.length) {
    if (other.str) {
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);  
    }
}

StringSet::~StringSet() {
    delete[] str;
}

StringSet StringSet::operator*(const StringSet& other) const {
    StringSet result;

    if (str && other.str) {
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < other.length; ++j) {
                if (str[i] == other.str[j]) {
                    result = result + str[i];
                    break;
                }
            }
        }
    }

    return result;
}

StringSet StringSet::operator+(char ch) const {
    StringSet result(*this);
    result += ch;
    return result;
}

StringSet& StringSet::operator+=(char ch) {
    char* newStr = new char[length + 2];
    if (str) {
        strcpy_s(newStr, length + 1, str);
        delete[] str;
    }

    newStr[length] = ch;
    newStr[length + 1] = '\0';
    str = newStr;
    ++length;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const StringSet& strSet) {
    if (strSet.str)
        os << strSet.str;
    return os;
}
