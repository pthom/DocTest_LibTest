#include <iostream>
#include "doctest.h"


int DocTestRegister2() {
    return 1;
}

TEST_CASE("testing in lib2.cpp") {
    std::cout << "testing in lib2.cpp" << std::endl;
    CHECK((1+1) == 2);
}
