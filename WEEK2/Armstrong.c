#include<stdio.h>
#include<unistd.h>
#define MSGSIZE 20
int main()
{
	int pid,r,sum=0,temp,n,p[2];
	char *msg1="Yes";
	char *msg2="No";
	char inbuf[MSGSIZE];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		printf("Inside Parent Process\n");
		printf("Enter an Integer:");
		scanf("%d",&n);
		temp=n;
		printf("Entered integer value is: %d\n",n);
		close(p[0]);
		write(p[1],&n,MSGSIZE);
	}
	else if(pid==0)
	{
		wait(1000);
		close(p[1]);
		printf("In Child Process\n");
		read(p[0],&n,MSGSIZE);
		while(n>0)    
		{    
			r=n%10;    
			sum=sum+(r*r*r);    
			n=n/10;    
		} 
		
		if(temp==sum)
		{   
			write(p[1],msg1,MSGSIZE);
			printf("Entered number is an armstrong  number \n"); 
		}   
		else    
		{
			write(p[1],msg2,MSGSIZE);
			printf("Entered number is not an armstrong number \n"); } 
		}
	}
	else
	{
		close(p[1])	;
		read(p[0],,MSGSIZE);
		printf("%d",n)
	}
}
