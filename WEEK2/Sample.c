#include<stdio.h>
#include<unistd.h>
int main()
{
	int p[2],retval;
	retval=pipe(p);
	printf("p[0] is %d and p[1] is %d\n",p[0],p[1]);
	int pid=fork();
	if(pid==0)
	{
		printf("This is Parent Process\n");
	}
	else if(pid>0)
	{
		printf("Error\n");
	}
	else 
	{
		printf("This is Child Process\n");
	}
}
