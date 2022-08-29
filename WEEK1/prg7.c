//Name:Al-Fareed
//Reg No:210970049
//Program to accept an integer before forking and child has to generate multiplication table corresponding to the integer.
//--------------------------------------------------------
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
int main()
{

	int n;
	printf("Enter a number whos table has to be generated : ");
	scanf("%d",&n);
	int pid=fork();
	if(pid>0)
	{
		for(int i=1;i<=10;i++)
		{
			int sum=n*i;
			printf("%d * %d = %d\n",n,i,sum);
		}
	}
return 0;
}
