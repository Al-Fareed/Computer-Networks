#include<stdio.h>
#include<unistd.h>
#define MSGSIZE 20
int main()
{
	int p[2],pid;
	int nums=0; 
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		nums=18;
		printf("In Parent \n");
		write(p[1],&nums,MSGSIZE);
	}
	else
	{
		printf("\nIn child Process");
		read(p[0],&nums,MSGSIZE);
		printf("\n%d\n",nums);
	}
}
