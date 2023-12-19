#ifndef STRINGSET_H
#define STRINGSET_H

#include <iostream>

class StringSet {
private:
    char* str;
    int length;

public:
    StringSet();
    StringSet(const char* s);
    StringSet(const StringSet& other);
    ~StringSet();

    StringSet operator*(const StringSet& other) const;
    StringSet operator+(char ch) const;
    StringSet& operator+=(char ch);

    friend std::ostream& operator<<(std::ostream& os, const StringSet& strSet);
};

#endif 
