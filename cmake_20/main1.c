#include<sys/types.h>
#include<sys/time.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<stdlib.h>

//读取键盘（标注输入--文件描述符为0），超时时间设置为2.5秒
//它只有在输入就绪时才读取键盘。
//它可以很容易通过添加其他描述符（如串线，管道，套接字等）进行扩展
int main()
{
    char buffer[128];
    int result, nread;

    fd_set inputs, testfds;
    struct timeval timeout;

    //初始化inputs，处理来自键盘的输入
    FD_ZERO(&inputs);
    FD_SET(0,&inputs);

    //在标准输入stdin上最多等待输入2.5秒
    while(1){
        testfds = inputs;
        timeout.tv_sec = 2;
        timeout.tv_usec = 500000; // 50万 microseconds 1000微秒等于1毫秒

        result = select(FD_SETSIZE,&testfds,(fd_set *)NULL, (fd_set *)NULL, &timeout);

        //经过这单时间之后，我们对result进行测试，如果没有输入，程序将再次循环，如果出现一个错误，程序将退出运行。
        switch (result)
        {
        case 0/* constant-expression */:
            printf("timeout\n");
            break;
        case -1:
            perror("select");
            exit(1);
        default:/*如果在等待期间，你对文件描述符采取了一些动作，程序就将读取标准输入stdin上的输入，
        并在接收到行尾字符后把他们都显示到屏幕上，当你输入到字符串是Ctr+D时，就退出程序*/
            if(FD_ISSET(0,&testfds)){
                /*
                https://www.cnblogs.com/geneil/archive/2011/12/04/2275372.html
                int ioctl(int fd,unsigned long cmd,...);
                fd:文件描述符
                cmd:控制命令
                ...:可选参数:插入*argp，具体内容依赖于cmd
                https://docs.oracle.com/cd/E36784_01/html/E36867/kermes8-28.html
                The FIONREAD ioctl returns the number of data bytes
                 (in all data messages queued) in the location pointed to by the arg parameter. 
                The ioctl returns a 32-bit quantity for both 32-bit and 64-bit application., 
                Therefore, code that passes the address of a long variable 
                needs to be changed to pass an int variable for 64–bit applications.
                */
                ioctl(0,FIONREAD,&nread);// ioctl – control device
                if(nread == 0){
                    printf("keyboard done\n");
                    exit(0);
                }
                nread = read(0,buffer,nread);
                buffer[nread] = 0;
                printf("read %d from keyboard: %s\n",nread, buffer);
            }
            break;
        }

    }
}