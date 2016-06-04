#include <stdio.h>
#define DEBUG // Quick hack against DOCTEST_BREAK_INTO_DEBUGGER not being defined
#include "doctest.h"

void HelloLibrary(){
    printf("Hello2 Library");
}


int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("testing the factorial function") {
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(10) == 3628800);
}


int fibo(int number) { return number < 2 ? number : fibo(number - 2) + fibo(number - 1); }

TEST_CASE("testing the fibo function") {
    CHECK(fibo(0) == 0);
    CHECK(fibo(1) == 1);
    CHECK(fibo(2) == 1);
    CHECK(fibo(3) == 2);
    CHECK(fibo(10) == 55);
}
