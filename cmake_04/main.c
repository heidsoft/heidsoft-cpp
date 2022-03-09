#include <stdio.h>

int main(int length, char *args[])
{
    //例1. 区别声明时，* 号在变量的位置
    int* b,c,d;
    printf("hello world\n");
    printf("%p\n",b);
    printf("%d\n",c);
    printf("%d\n",d);
    //例2. 区别如上声明，例1中的 * 只对变量b生效, 同时声明三个 指向int类型的指针，需要如下声明。
    int *e,*f,*j;
    printf("%p\n",e);
    printf("%p\n",f);
    printf("%p\n",j);

    //例3 
    char *message="heidsoft cpp";
    printf("%p\n",message);
    printf("%s\n",message);
    printf("%c\n",*message);
    printf("%c\n",*message++);

    //例4 例3等同于如下
    //char *message
    //message = "heidsoft cpp";
     

    return 1;
}