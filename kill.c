/* $begin kill */
#include "csapp.h"

int main() 
{
    pid_t pid;
    //printf("haha");

    /* Child sleeps until SIGKILL signal received, then dies */   
    if ((pid = Fork()) == 0) {   
	while(1){
        printf("control should never reach here!\n");
    }
	
	
    }
    sleep(1);
    /* Parent sends a SIGKILL signal to a child */
    Kill(pid, SIGKILL);
    exit(0);
}
/* $end kill */
