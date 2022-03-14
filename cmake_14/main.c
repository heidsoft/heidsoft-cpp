#include <stdlib.h>
#include <stdio.h>
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
