#include "csapp.h"
#define N 5


unsigned int snooze(unsigned int secs)
{
    unsigned int leftsecs = sleep(secs);
    printf("Slept for %u of %u secs.\n",secs-leftsecs,secs);
    return leftsecs;
}


int main()
{
    int status, i;
    pid_t pid[N];
    pid_t retpid;

    for(i=0;i<N;i++){
        if((pid[i]=Fork())==0){
            printf("%d: ",i);
            snooze(2);
            exit(100+i);
        }
        
    }

    i=0;
    while((retpid=waitpid(pid[i++],&status,0))>0){
        if(WIFEXITED(status))
        {
            printf("child %d terminated normally with exit status=%d\n",retpid,WEXITSTATUS(status));

        }
        else{
            printf("child %d terminated abnormallly\n",retpid);
        }
    }

    if(errno != ECHILD){
        unix_error("waitpid error");
    }

    exit(0);
}