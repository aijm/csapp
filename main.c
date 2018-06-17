#include "csapp.h"




int main(void)
{
    pid_t pid;
    int x= 1;
    pid = Fork(); // 创建子进程，调用一次，父进程中返回子进程id，子进程返回0
    if(pid == 0){ // 若为子进程
        printf("child: x=%d\n",++x);
        exit(0);
    }

    /* parent */
    printf("parent: x=%d\n",--x);

    // 子进程有独立的地址空间，所以对于变量相当于拷贝，父进程和子进程中的x是不同的


    // write(1,"hello, world\n",13);
    
    // _exit(0);
}