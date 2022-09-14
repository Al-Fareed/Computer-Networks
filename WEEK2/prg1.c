#include<stdio.h>
#include<string.h>
#include<unistd.h>
#define MSGSIZE 20
int main()
{
	int p[2],pid;
	int nums=0; 
	char str[50];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		nums=18;
		printf("In Parent \nEnter a String:");
		scanf("%s",str);
		write(p[1],&str,MSGSIZE);
	}
	else
	{
		printf("\nIn child Process");
		read(p[0],&str,MSGSIZE);
		printf("\nString entered in Parent process:%s\n",str);
		int len=strlen(str);
		printf("Total length of the string is:%d\n",len);
		int alpha=0,digit=0;
		for(int i=0;i<len;i++)
		{
			if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))
				alpha++;
			else if(str[i]>=48 && str[i]<=57)
				digit++;

		}
		printf("Number of characters in the string is: %d \n and number of digits in the string is:%d\n",alpha,digit);
	}
}
