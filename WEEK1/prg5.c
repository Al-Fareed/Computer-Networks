//Reg No:210970049
//Program to write some characters to a file and close it in the parent. Child should open the same file in child and display.
//--------------------------------------------------------
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	char buf;
	char fl[25],chars[50];
	int fdOne, fdTwo;
	printf("Enter a file name : ");
	scanf("%s",fl);
	fdOne=open(fl,O_WRONLY);
	printf("\nEnter some characters to be written in file %s : ",fl);
	scanf("%s",chars);
	int len=strlen(chars);
	write(fdOne,&chars,len);
	close(fdOne);
	int pid=fork();
	if(pid>0)
	{
		printf("\nParent process id is = %d ",getppid());
		printf("\nChild process id is=%d",getpid());
		fdTwo=open(fl,O_RDONLY);
		printf("\nCharacters in the file is : ");
		while(read(fdTwo,&buf,1))
		{
			printf("%c",buf);
		}
		close(fdTwo);
	}
return 0;
}
