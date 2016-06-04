#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


void DocTest_Enabler();

int main(int argc, char** argv) {
  doctest::Context context(argc, argv);

  int res = context.run();
  if(context.shouldExit())
    return res;

  DocTest_Enabler();
  return res;
}
