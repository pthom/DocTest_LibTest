#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


int DocTestRegister1();
int DocTestRegister2();

int main(int argc, char** argv) {
  doctest::Context context(argc, argv);

  int res = context.run();
  if(context.shouldExit())
    return res;

  DocTestRegister1();
  DocTestRegister2();
  return res;
}
