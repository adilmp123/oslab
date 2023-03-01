#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int pid;
    pid = fork();
    if(pid<0)
    {
        printf("fork failed");
    }
    else if(pid==0)
    {
        printf("inside child process ! ");
        printf("child id = %d\nparent id = %d\n",pid,getpid());
        exit(0);
    }
    else
    {
        printf("Process id is - %d\n",getpid());
        exit(0);
    }
}
