#include "csapp.h"

unsigned int snooze(unsigned int secs)
{
    unsigned int leftsecs = sleep(secs);
    printf("Slept for %u of %u secs.\n",secs-leftsecs,secs);
    return leftsecs;
}

void sigint_handler(int sig)
{
    return;
}

int main(int argc,char* argv[])
{
    if(argc!=2){
        fprintf(stderr,"usage: %s <secs>\n",argv[0]);
    }

    if(signal(SIGINT,sigint_handler)==SIG_ERR)
    {
        unix_error("signal error");
    }

    snooze(atoi(argv[1]));

    

    return 0;
}