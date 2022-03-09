#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add/add.hpp"

//例子 cmake 子目录工程 与 链接非标准库的构建
int main(int length, char *args[])
{

    int c = add(1,1);   
    printf("add result %d\n",c);
    return 1;
}