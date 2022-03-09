#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "asyncmonitorsignal.h"
#define BLKSIZE 1024
//https://www.gnu.org/software/libc/manual/html_node/Permission-Bits.html
/**
 * @heidsoft@qq.com
 * 
 * S_IRUSR：用户读权限
 * S_IWUSR：用户写权限
 * S_IRGRP：用户组读权限
 * S_IWGRP：用户组写权限
 * S_IROTH：其他组读权限
 * S_IWOTH：其他组写权限
 */
#define NODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

void dowork(void);

#ifdef SIGRTMAX
#define MAX_SIGNAL_ID SIGRTMAX
#else
/* Darwin doesn't define SIGRTMAX.
 * kill will still reject an invalid signal ID with EINVAL, though
 * reporting it upfront would be better. */
#define MAX_SIGNAL_ID 32
#endif

//The variables are named argc (argument count) and argv (argument vector) by convention（习惯）,
//https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean
int main(int argc, char *argv[])
{
    char buf[BLKSIZE];
    int done = 0;
    int error;
    int fd1;
    int fd2;
    // 打开I/O文件描述符
    if(argc !=3){
        fprintf(stderr,"Usage: %s filename1 filename2\n",argv[0]);
        return 1;
    }
    if((fd1 = open(argv[1],O_RDONLY))==-1){
        fprintf(stderr,"Failed to open %s:%s",argv[0],strerror(errno));
    }

    if((fd2 = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC))==-1){
        fprintf(stderr,"Failed to open %s:%s",argv[0],strerror(errno));
    }

    if(initsignal(MAX_SIGNAL_ID)== -1){
        perror("Failed to initialize signal");
        return 1;
    }

    if(initread(fd1,fd2,MAX_SIGNAL_ID,buf,BLKSIZE) == -1){
        perror("Failed to initate the first read");
        return 1;
    }

    for(;;){
        dowork();
        if(!done){
            if(done == getdone()){
                if(error = geterror()){
                    fprintf(stderr,"Failed to copy file:%s\n",strerror(error));
                }else{
                     fprintf(stderr,"Copy successful %d bytes\n",getbytes());
                }
            }
        }
    }

    return 1;
}

/**
函数的隐式声明
  cmake_06 git:(master) ✗ make
[ 50%] Building C object CMakeFiles/heidsoft.exe.dir/main.c.o
/Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_06/main.c:56:8: error: implicit declaration of function 'initsignal' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
    if(initsignal(MAX_SIGNAL_ID)== -1){
       ^
/Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_06/main.c:61:8: error: implicit declaration of function 'initread' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
    if(initread(fd1,fd2,MAX_SIGNAL_ID,buf,BLKSIZE) == -1){
       ^
/Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_06/main.c:69:24: error: implicit declaration of function 'getdone' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
            if(done == getdone()){
                       ^
/Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_06/main.c:70:28: error: implicit declaration of function 'geterror' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
                if(error = geterror()){
                           ^
/Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_06/main.c:70:26: warning: using the result of an assignment as a condition without parentheses [-Wparentheses]
                if(error = geterror()){
                   ~~~~~~^~~~~~~~~~~~
/Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_06/main.c:70:26: note: place parentheses around the assignment to silence this warning
                if(error = geterror()){
                         ^
                   (                 )
/Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_06/main.c:70:26: note: use '==' to turn this assignment into an equality comparison
                if(error = geterror()){
                         ^
                         ==
/Users/heidsoft/Downloads/research/heidsoft-cpp/cmake_06/main.c:73:66: error: implicit declaration of function 'getbytes' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
                     fprintf(stderr,"Copy successful %d bytes\n",getbytes());
                                                                 ^
1 warning and 5 errors generated.
make[2]: *** [CMakeFiles/heidsoft.exe.dir/main.c.o] Error 1
make[1]: *** [CMakeFiles/heidsoft.exe.dir/all] Error 2
make: *** [all] Error 2 
 */