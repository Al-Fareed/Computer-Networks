#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define max 3330
int main()
{
	int num,n,rem,res=0;
	int p[2],p1[2],pid;
	pipe(p);
	pipe(p1);
	char inbuff[max];
	pid=fork();
	if(pid>0)
	{
     		printf("Enter a number:");
		scanf("%d",&num);
		n=num;
		write(p[1],&num,sizeof(num));
		read(p1[0],inbuff,max);
		printf("\n");
		printf("\n%s",inbuff);
	}
	else
	{
		read(p[0],&num,sizeof(num));
		n=num;
		while(n!=0)
		{
			rem=n%10;
			res=res+(rem*rem*rem);
			n=n/10;
		}
		if(res==num)
			write(p1[1],"Yes,its a armstrong number",max);
		else
			write(p1[1],"No,its not a armstrong Number",max);
	}
	return 0;
}

