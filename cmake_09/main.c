#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 
 ➜  cmake_09 git:(master) ✗ ./heidsoft.exe 
Enter you first name:1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
[1]    60503 abort      ./heidsoft.exe
产生溢出
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    char buf[80];
    printf("Enter you first name:");
    scanf("%s",buf);
    return 1;
}

