#include <iostream>
#define DEBUG // Quick hack against DOCTEST_BREAK_INTO_DEBUGGER not being defined
#include "doctest.h"

int DocTestRegister1() {
  return 1;
}

int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("testing the factorial function") {
  std::cout << "testing in lib1.cpp" << std::endl;
  CHECK(factorial(1) == 1);
  CHECK(factorial(2) == 2);
  CHECK(factorial(10) == 3628800);
}
