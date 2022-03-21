#include <stdio.h>
int main() {
    int n = 1;

    printf("&n:  %p\n",&n);
    printf("(char *)&n:  %c\n",(char *)&n);
    printf("*(char *)&n:  %d\n",*(char *)&n);
    // little endian if true
    if(*(char *)&n == 1) {
        printf("Little endian\n");
    } else {
        printf("Big endian\n");
    }   
}