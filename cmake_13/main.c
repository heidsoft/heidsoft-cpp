#include <stdlib.h>
#include <stdio.h>
int main(int argc, const char * argv[]) {
  int a = 112, b =-1;
  float c = 3.14;
  int *d = &a;
  float *e = &c;

  printf("a:  %d\n",a);
  printf("b:  %d\n",b);
  printf("c:  %f\n",c);
  //变量的值
  printf("*d:  %p\n",d);
  printf("*e:  %p\n",e);
  //指向地址所 存储的数值
  printf("*d ->value:  %d\n",*d);
  printf("*e ->value:  %f\n",*e);
  //变量本身所存储的地址
  printf("&d ->address:  %p\n",&d);
  printf("&e ->address:  %p\n",&e);
  return 1;
}
/**

➜  cmake13 git:(master) ✗ ./a.out 
a:  112
b:  -1
c:  3.140000
*d:  0x7ff7b44b9f5c
*e:  0x7ff7b44b9f54
*d ->value:  112
*e ->value:  3.140000
➜  cmake13 git:(master) ✗ cc main.c 
➜  cmake13 git:(master) ✗ ./a.out 
a:  112
b:  -1
c:  3.140000
*d:  0x7ff7b907ff5c
*e:  0x7ff7b907ff54
*d ->value:  112
*e ->value:  3.140000
&d ->address:  0x7ff7b907ff48
&e ->address:  0x7ff7b907ff40
➜  cmake13 git:(master) ✗ 

 */