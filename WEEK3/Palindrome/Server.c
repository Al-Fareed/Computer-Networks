#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int fd;
	char string1[64];
	char msgbuf[50];
char* msg1="Not a palindrome ";
char* msg2="is a Palindrome";
	fd=open("vmfifo",O_RDWR);
	/*if (fd<0)
	{
		perror("vmfifo open failed");
		exit(1);
	}*/
	fd=open("vmfifo",O_RDWR);
	read(fd,string1,sizeof(string1));
	close(fd);
	
	printf(" Message received : %s\n",string1);
	int i=0, l=strlen(string1)-1;

fd=open("vmfifo",O_WRONLY);
	while(l>i)
{
	if(string1[i++]!=string1[l--])
	{
		write(fd,msg1,50);
close(fd);
return 0;
	}
}
write(fd,msg2,50);

close(fd);
return 0;




    			/*int flag = 0;	
			length = strlen(string1);
			for(i=0;i < length ;i++){
			if(string1[i] != string1[length-i-1]){
			    flag = 1;
			    break;
			   }
			}
		    
		    if (flag) {
			msgbuf="Palindrome";
			write(fd,msgbuf,sizeof(msgbuf));
			printf("%s is not a palindrome\n", string1);
		    }    
		    else {
			msgbuf="not_Palindrome";
			write(fd,msgbuf,sizeof(msgbuf));
			printf("%s is a palindrome\n", string1);
		    }
	}
	else
		printf(" Not reading from pipe\n");*/
//	close(fd);
//	return(0);
}
