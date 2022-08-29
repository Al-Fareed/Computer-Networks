#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int fd,fi,nread;
	char msg[50];
	char msgbuf[64];
	//open named pipe created in n_pipe1.c
	fd=open("vmfifo",O_RDWR);
	if (fd<0)
	{
		perror("vmfifo open failed");
		exit(1);
	}
	fd=open("vmfifo",O_RDWR);
	nread=read(fd,msgbuf,sizeof(msgbuf));
	if(nread>0)
	{
			printf(" Message received : %s\n",msgbuf);
	}
	else
		printf(" Not reading from pipe\n");
	close(fd);
	return(0);
}
