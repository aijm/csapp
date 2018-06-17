#include "csapp.h"

int main(int argc,char* argv[],char* envp[])
{
    int i;
    printf("Commandline arguments:\n");
    for(i=0;i<argc;i++){
        printf("argv[%d]: ",i);
        printf("%s\n",argv[i]);
        
    }

    printf("Environment variables:\n");
    i=0;
    while(envp[i]){
        printf("envp[%d]: ",i);
        printf("%s\n",envp[i]);
        
        i++;
    }
    


    exit(0);
}