#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printb(unsigned int v) {
    unsigned int i, s = 1<<((sizeof(v)<<3)-1); // s = only most significant bit at 1
    for (i = s; i; i>>=1) printf("%d", v & i || 0 );
}

int main(int argc, char *argv[])
{
    
    unsigned int value = 8;
    unsigned int bit_number = 1;
    // 打印无符号long类型 长度
    printf("%lu\n",sizeof(value));
    printb(value);
    // 00000000000000000000000000000010 
    // 00000000000000000000000000000001
    // 00000000000000000000000000000011
    // 把指定的位设置 1
    value = value | 1 <<bit_number;
    printf("位的操纵： %d\n",value);
    printb(value);
    return 1;
}