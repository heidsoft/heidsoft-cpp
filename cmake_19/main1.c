#include<stdio.h>
void func(void) {
    // 默认初始化未0
    static int count; // If you don't declare its value, it is initialized with zero
    printf("%d \n", count);
    ++count;
}

int main(void) {
    int index = 0;
    while(1) {
        index++;
        func();
        if (index > 100){
            break;
        }
    }
    return 0;
}