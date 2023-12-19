#include "stringset.h"

int main() {
    StringSet str1("sdqcg");
    StringSet str2("rgfas34");

    StringSet intersection = str1 * str2;

    std::cout << "String 1: " << str1 << std::endl;
    std::cout << "String 2: " << str2 << std::endl;
    std::cout << "Intersection: " << intersection << std::endl;

    return 0;
}
