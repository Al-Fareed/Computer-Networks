#include <stdio.h>
#include <unistd.h>
#include<string.h>
#define MSGSIZE 2000
int main()
{
	int pid, r, sum = 0,temp, n,p[2],p1[2];
	char inbuf[MSGSIZE];
	pipe(p);
	pipe(p1);
	pid = fork();
	if (pid > 0)
	{
		printf("Enter an Integer:");
		scanf("%d", &n);
		printf("Entered integer value is: %d\n", n);
		write(p[1], &n, sizeof(n));
		read(p1[0],inbuf,MSGSIZE);
		printf("Armstrong: %s\n",inbuf);
	}
	else
	{
		read(p[0], &n, MSGSIZE);
		temp=n;
		while (n > 0)
		{
			r = n % 10;
			sum = sum + (r * r * r);
			n = n / 10;
		}

		if (temp == sum)
		{
			write(p1[1], "Yes", MSGSIZE);
		}
		else
		{
			write(p1[1], "No", MSGSIZE);
		}
	}
	
}