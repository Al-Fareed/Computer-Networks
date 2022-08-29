#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#define BufSize 64
int main()
{
	int fd,fi,nwrite;
	char msgbuf[BufSize];
	fi=mkfifo("vmfifo",0777);
	printf("Enter a message : ");
	scanf("%s",msgbuf);
	/*if(fi<0)
	{
		perror("vmfifo creation failed");
		exit(1);
	}*/
	fd=open("vmfifo",O_WRONLY);
	if (fd<0)
	{
		perror("vmfifo open failed");
		exit(1);
	}
	nwrite=write(fd,msgbuf,sizeof(msgbuf));
	if(nwrite<=0)
		perror("message write failed \n");
	else
		printf("Message sent successfully\n");
	close(fd);
	return(0);
}
