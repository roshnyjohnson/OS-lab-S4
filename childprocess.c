#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
//#include<sys/wait.h>

int main()
{
pid_t pid;
pid=fork();
if(pid<0)
{
        printf("error");

}
else if(pid==0)
{
        printf("this is the child process and child pid is %d and parent pid is %d \n ",getpid(),getppid());

}
else
{
        printf("this the arent process and pid of parent is %d and pid of child is %d",getpid(),pid);
}
wait(NULL);
}
