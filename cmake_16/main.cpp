#ifdef __cplusplus
// if we are being compiled with a C++ compiler then declare the
// following functions as C functions to prevent name mangling.
// C语言 与 C++ 混合使用场景，采用C++编译器编译
// https://isocpp.org/wiki/faq/mixing-c-and-cpp#overview-mixing-langs
// http://yosefk.com/c++fqa/mixing.html#fqa-32.1
// https://www.oracle.com/technical-resources/articles/it-infrastructure/mixing-c-and-cplusplus.html
// https://docs.microsoft.com/en-us/cpp/cpp/new-operator-cpp?view=msvc-170
extern "C" {
#include <stdio.h>
#endif

// exported C function list.
int foo (void);

int main(int argc, const char * argv[]) {

  int a;
  int *d = &a;
  printf("a: %d\n",a);
  printf("d: %p\n",d);
  printf("*d: %d\n",*d);
  // 静态类型默认初始化为0
  static int b;
  printf("b: %d\n",b);

  // 指针类型作为左值
  *d = 10 - *d;
  printf("c: %d\n",*d);
  return 1;
}

#ifdef __cplusplus
// if this is a C++ compiler, we need to close off the extern declaration.
};
#endif