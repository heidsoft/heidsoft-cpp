#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 
 * ➜  cmake_10 git:(master) ✗ ./heidsoft.exe 
Enter you first name:1111111111111111111111111111111111111111111111111111111111
由于有截断，没有产生溢出
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    char buf[80];
    printf("Enter you first name:");
    scanf("%79s",buf);
    return 1;
}

