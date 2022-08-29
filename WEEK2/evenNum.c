#include<stdio.h>
#include<unistd.h>
#define MSGSIZE 20
int main()
{
	int p[2],pid;
	int nums[25]; 
	char inbuf[MSGSIZE];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		printf("In Parent \nEnter 10 numbers:\n");
		for(int i=0;i<10;i++)
		{
			scanf("%d",&nums[i]);
			write(p[1],&nums[i],MSGSIZE);
		}
		
	}
	else if(pid==0)
	{
		printf("Even numbers are:\n");
		for(int i=0;i<10;i++)
		{
			read(p[0],&nums[i],MSGSIZE);
			if(nums[i]%2==0)
			{
				
				printf("%d\t",nums[i]);
			}
		}
	}
	else{}
}
