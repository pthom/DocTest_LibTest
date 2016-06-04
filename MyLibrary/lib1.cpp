#include <stdio.h>
#define DEBUG
#include "doctest.h"

//Note : I have a bug under OSX / Xcode : DOCTEST_BREAK_INTO_DEBUGGER is not defined
// the line below is a quick hack to silence the error...
//#define DOCTEST_BREAK_INTO_DEBUGGER()

void HelloLibrary(){
    printf("Hello2 Library");
}
TEST_CASE("Basic Test") {
  static int ashram = 2;
  CHECK(ashram == 2);
  ashram++;
}
