#include<stdio.h>
#include<unistd.h>
#define MSGSIZE 16
int main()
{

	int p[2],pid;
	char *msg1="Hello World";
	int inbuf[MSGSIZE];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		printf("In Parent \n");
		write(p[1],msg1,MSGSIZE);
	}
	else
	{
		printf("\nIn Child\n");
		read(p[0],inbuf,MSGSIZE);
		printf("\n%s\n",inbuf);
	}
}
