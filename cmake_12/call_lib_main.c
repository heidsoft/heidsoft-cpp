// 调用库程序

#include <stdlib.h>
#include "lib.h"

int main()
{
    bill("call bill 函数测试。");

    //退出函数
    exit(0);
}

/*
➜  cmake_12 git:(master) ✗ cc -c call_lib_main.c 
➜  cmake_12 git:(master) ✗ cc -o call_lib_main call_lib_main.o bill.o 
➜  cmake_12 git:(master) ✗ ./call_lib_main 
bill: 传入参数是call bill 函数测试。
➜  cmake_12 git:(master) ✗ 
*/