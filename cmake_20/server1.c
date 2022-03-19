#include<sys/types.h>
#include<sys/time.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
    int server_sockfd, client_sockfd;
    /*
    server1.c:81:95: warning: passing 'int *' to parameter of type 'socklen_t *' (aka 'unsigned int *') converts between pointers to integer types with different sign [-Wpointer-sign]
                    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
                                                                                              ^~~~~~~~~~~
/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/socket.h:704:73: note: passing argument to parameter here
int     accept(int, struct sockaddr * __restrict, socklen_t * __restrict)
    提示   socklen_t  --> unsigned int
     */
    unsigned int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int result;
    fd_set readfds, testfds;

   
    /*
            Provides sequenced, reliable, two-way, connection-based
              byte streams.  An out-of-band data transmission mechanism
              may be supported.

       SOCK_DGRAM
              Supports datagrams (connectionless, unreliable messages of
              a fixed maximum length).

       SOCK_SEQPACKET
              Provides a sequenced, reliable, two-way connection-based
              data transmission path for datagrams of fixed maximum
              length; a consumer is required to read an entire packet
              with each input system call.

       SOCK_RAW
              Provides raw network protocol access.

       SOCK_RDM
              Provides a reliable datagram layer that does not guarantee
              ordering.

       SOCK_PACKET
              Obsolete and should not be used in new programs; 
     */
     //为服务器创建并命名一个套接字
    server_sockfd = socket(AF_INET,SOCK_STREAM,0);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);

    bind(server_sockfd,(struct sockaddr *)&server_address,server_len);

    //创建一个连接队列，初始化readfds 以及处理来自server_sockfd的输入
    listen(server_sockfd,5);

     //初始化readfds，处理来自键盘的输入
    FD_ZERO(&readfds);
    FD_SET(server_sockfd,&readfds);

    //现在开始等待客户和请求的到来，因为你给timeout参数传递了一个空指针，所以select调用
    //将不会发生超时，如果select调用的返回值小于1，程序将退出并报告出现的错误
    while(1){
        char ch;
        int fd;
        int nread;
        testfds = readfds;
        result = select(FD_SETSIZE,&testfds,(fd_set *)NULL, (fd_set *)NULL, (struct timeval *)NULL);
        if(result < 1){
            perror("读取数据错误");
            exit(1);
        }
        // 一旦得知有活动发生，可以用FD_ISSET来依次检查每个描述符，以发现活动发生在那个描述符上。
        for(fd = 0; fd < FD_SETSIZE; fd++){
            if(FD_ISSET(fd,&testfds)){
                // 如果活动发生在套接字server_sockfd上，它肯定是一个新的连接请求，
                // 你就把相关的client_sockfd添加到描述集合中
                if( fd == server_sockfd ){
                    client_len = sizeof(client_address);
                    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
                    FD_SET(client_sockfd,&readfds);
                    printf("添加 客户端的文件描述符： %d\n",client_sockfd);
                }else{
                    ioctl(fd,FIONREAD, &nread);

                    if( nread == 0 ){
                        close(fd);
                        FD_CLR(fd,&readfds);
                        printf("清除客户端文件描符: %d\n", fd);
                    }else{
                        read(fd, &ch,1);
                        sleep(5);
                        printf("服务端获取客户端文件描述符：%d 的数据\n",fd);
                        ch++;
                        write(fd,&ch,1);
                    }
                }
            }
        }
    }
        

}