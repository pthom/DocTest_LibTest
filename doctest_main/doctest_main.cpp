#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int DocTestRegister();

int main(int argc, char** argv) {
  doctest::Context context(argc, argv);

  int res = context.run();
  if(context.shouldExit())
    return res;

  DocTestRegister();
  return res;
}
