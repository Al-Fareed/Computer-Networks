#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
int main()
{

int a=10;
int pid=fork();
if(pid<0)
{
	printf("child not created");
}
else if(pid>0)
{
printf("PARENT id %d and pid returned by fork() %d\n",getpid(),pid);
wait(0);
}
else
{
printf("Child pid: %d --Parent id %d",getpid(),getppid());
printf("Child pid returned by fork() %d\n",pid);
}
}


