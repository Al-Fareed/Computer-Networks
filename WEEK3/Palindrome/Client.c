#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#define BufSize 64
int main()
{
	int fd;
	char msgbuf[BufSize];
	char output[50];
	mkfifo("vmfifo",0777);
	printf("Enter a message : ");
	scanf("%s",msgbuf);
	
	fd=open("vmfifo",O_WRONLY);
	/*if (fd<0)
	{
		perror("vmfifo open failed");
		exit(1);
	}*/
	write(fd,msgbuf,sizeof(msgbuf));
	/*if(nwrite<=0)
		perror("message write failed \n");
	else
		printf("Message sent successfully\n");*/
	close(fd);
	fd=open("vmfifo",O_RDONLY);
	read(fd,output,50);
	close(fd);
	printf("Seerver message %s:\n",output);
	return(0);
}
