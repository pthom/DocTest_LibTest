#include <stdio.h>
#define DEBUG // Quick hack against DOCTEST_BREAK_INTO_DEBUGGER not being defined
#include "doctest.h"

void HelloLibrary(){
    printf("Hello2 Library");
}
TEST_CASE("Basic Test") {
  static int ashram = 2;
  CHECK(ashram == 2);
  ashram++;
}
