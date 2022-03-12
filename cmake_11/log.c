#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "log.h"

// TODO日志实现
typedef struct list_struct{
    data_t item;
    struct list_struct *next;
}log_t;

int addmsg(data_t data){
    return 0;
}

void clearlog(void){
    puts("clearlog");
}

char *getlog(void){
    return NULL;
}

int savelog(char *filename){
    return 0;
}