/**
 * @file main.c
 * @author jake.liu (heidsoft@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdio.h>

//Types and data structures
//typedef void aeFileProc(struct aeEventLoop *eventLoop, int fd, void *clientData, int mask);
//typedef int aeTimeProc(struct aeEventLoop *eventLoop, long long id, void *clientData);
//typedef void aeEventFinalizerProc(struct aeEventLoop *eventLoop, void *clientData);
//typedef void aeBeforeSleepProc(struct aeEventLoop *eventLoop);

// 定义函数类型
typedef void void_a(int fd);
typedef int  int_b(long fd);

// 定义指针函数类型
typedef void (*void_aa)(int fd);
typedef int  (*int_bb)(long fd);

void a(int fd){
    printf("a指针函数测试: %d\n",fd);
}

int b(long fd){
    printf("b指针函数测试: %ld\n",fd);
    return 1;
}

// https://stackoverflow.com/questions/4295432/typedef-function-pointer
// https://stackoverflow.com/questions/44327364/c-function-pointer-and-typedef
// https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)FunctionPointers.html
// https://www.cs.uaf.edu/courses/cs301/2014-fall/notes/methods/

int main(int argc, const char * argv[]) {
    // 函数原型非指针类型时
    void_a *p_a_func = &a;
    // 函数原型指针类型，变量没有带间接引用
    void_aa p_aa_func = &a;
    p_a_func(10);
    p_aa_func(10);
    // 函数原型非指针类型时
    int_b *p_b_func = &b;
    // 函数原型指针类型,变量没有带间接引用
    int_bb p_bb_func = &b;
    p_b_func(100L);
    p_bb_func(100L);

    return 1;
}

