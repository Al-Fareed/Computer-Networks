#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define MSGSIZE 10
int main()
{
	int p[2],pid,p1[2],j=-1;
	int nums[25],evenNums[25]; 
	char inbuf[MSGSIZE];
	pipe(p);
	pipe(p1);
	pid=fork();
	if(pid>0)
	{
		printf("In Parent \nEnter 10 numbers:\n");
		for(int i=0;i<10;i++)
		{
			scanf("%d",&nums[i]);
			write(p[1],&nums[i],MSGSIZE);
			
		}
		int val=read(p[1],evenNums,sizeof(evenNums));
		for(int i=0;i<val;i++)
		{
			printf("%d\t",evenNums[i]);
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
				evenNums[i]=nums[i];
				write(p1[1],&evenNums[i],MSGSIZE);
			}
		}
	}
	printf("\n");
}
