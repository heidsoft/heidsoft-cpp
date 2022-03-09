#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int length, char *args[])
{
    //例1 char *ptr_to_char1 声明指向一个字符的指针变量
    char *ptr_to_char1;

    //例2 typedef char *ptr_to_char;  把ptr_to_char 作为指向字符的指针类型的新名称
    typedef char *ptr_to_char;

    ptr_to_char a;
    a = "hello world";
    printf("通过新变量名称声明后赋值1：%s\n",a);
    a = malloc(strlen("hello typedef"));
    sprintf(a,"%s","hello typedef");
    printf("通过新变量名称声明后赋值2：%s\n",a);
    
    return 1;
}