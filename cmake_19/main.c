#include <stdio.h>

// In the C programming language, static is used with global variables and functions to set their scope to the containing file. In local variables, static is used to store the variable in the statically allocated memory instead of the automatically allocated memory. 
void foo()
{
    int a = 10;
    static int sa = 10;

    a += 5;
    sa += 5;

    printf("a = %d, sa = %d\n", a, sa);
}

/*
➜  cmake_19 git:(master) ✗ ./a.out 
a = 15, sa = 15
a = 15, sa = 20
a = 15, sa = 25
a = 15, sa = 30
a = 15, sa = 35
a = 15, sa = 40
a = 15, sa = 45
a = 15, sa = 50
a = 15, sa = 55
a = 15, sa = 60
*/
// https://stackoverflow.com/questions/572547/what-does-static-mean-in-c?rq=1
int main()
{
    int i;

    for (i = 0; i < 10; ++i)
        foo();
}