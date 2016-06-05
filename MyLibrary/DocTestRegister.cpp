
int DocTestRegister_lib1();
int DocTestRegister_lib2();

int DocTestRegister()
{
  int sum;
  sum += DocTestRegister_lib1();
  sum += DocTestRegister_lib2();
  return sum;
}