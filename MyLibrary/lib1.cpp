#include <stdio.h>
#include "doctest.h"

//Note : I have a bug under OSX / Xcode : DOCTEST_BREAK_INTO_DEBUGGER is not defined
// the line below is a quick hack to silence the error...
//#define DOCTEST_BREAK_INTO_DEBUGGER()

void HelloLibrary(){
    printf("Hello Library");
}
TEST_CASE("Basic Test") {
  int a = 2;
  CHECK(a == 2);
}
