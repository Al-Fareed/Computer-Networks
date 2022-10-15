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

int sockfd , newssockfd ,n, retval;
socklen_t actuallen;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr,clientaddr;
char buff[MAXSIZE];
int a=0;

sockfd = socket(AF_INET,SOCK_DGRAM,0);
if(sockfd == -1)
{

printf("\nSocket creation failed");
exit(-1);
}

serveraddr.sin_family = AF_INET;
serveraddr.sin_port = htons(3387);
serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
retval = bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval == -1)
{
printf("Binding error");
close(sockfd);
exit(0);
}

while(1) 
    {
         actuallen = sizeof(clientaddr);
       recedbytes = recvfrom(sockfd, buff ,sizeof(buff),0,(struct sockaddr*)&clientaddr,&actuallen);
        printf("From client: %s To client : ", buff);
	   n = 0;
	    while ((buff[n++] = getchar()) != '\n');
         sentbytes=sendto(sockfd , buff ,sizeof(buff),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
         if (strncmp("end", buff, 3) == 0) 
        {
	   printf("Server Exit...\n");
	   break;
	}
    }   
close(newssockfd);
close(sockfd);
}





