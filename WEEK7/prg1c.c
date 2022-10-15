#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#define MAXSIZE 50

int main()
{
socklen_t actuallen;
int sockfd , retval,n;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr;
char buff[MAXSIZE];
sockfd = socket(AF_INET,SOCK_DGRAM,0);
if(sockfd==-1)
{

printf("\nsocket creation failed");
exit(-1);
}

serveraddr.sin_family = AF_INET;
serveraddr.sin_port=htons(3387);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
while(1)
    {
       printf("Enter the string : ");
       n = 0;
       while ((buff[n++] = getchar()) != '\n');
       sentbytes= sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr) );
    
      actuallen = sizeof(serveraddr);
     recedbytes= recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&serveraddr,&actuallen);
	printf("From Server : %s", buff);
	if ((strncmp(buff, "end", 3)) == 0) 
        {
	  printf("Client Exit...\n");
	  break;
	}
   }
   close(sockfd);
}





