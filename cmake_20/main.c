#include<sys/select.h>
//NULL
#include<unistd.h>
#include<stdio.h>

//int select(int nfds, fd_set *restrict readfds, 
//fd_set *restrict writefds, fd_set *restrict errorfds, 
//struct timeval *restrict timeout);
//select函数中间三个参数（指向描述符集的指针）中的任意一个或全部都可以是空指针，这表示对相应状态不关心。
//如果三个指针都是空指针，则select提供了脚sleep更精确的计时器。
//select的第一个参数nfds，是最大描述符加1，在三个描述符集中找出最大描述编号值，然后加1.
//也可以将第一个参数设置为FD_SETSIZE, 他说明了最大描述符数。但是对大多数应用程序而言，此值太大了。多数应用程序只
//使用3-10个描述符。
//如果将第三个参数设置为我们所关注的最大描述符编号值加1，内核就只需在此范围内寻找打开的位，而不必在三个描述符集中
//的数百位内搜索。
int main()
{
    //声明描述集
    fd_set rd;
    struct timeval tv;
    int err;

    FD_ZERO(&rd);
    FD_SET(0,&rd);

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    err = select(1,&rd,NULL,NULL,&tv);

    if(err == 0){
        printf("select timeout!\n");
    }else if(err == 1){
        printf("fail to select!\n");
    }else{
        printf("data is available!\n");
    }
    return 0;
}