#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAXSIZE 50

struct account
{
    unsigned long int accno;
    int pin;
    float amount;
};

int main()
{
    int sockfd, retval;
    int recedbytes, sentbytes;
    socklen_t actuallen;
    struct sockaddr_in serveraddr;
    char buff[MAXSIZE];
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1)
    {
        printf("\nSocket creation error");
        exit(0);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3387);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
   

    struct account acc;

    printf("Enter Account No: ");
    scanf("%lu", &acc.accno);
    printf("Enter Pin: ");
    scanf("%d", &acc.pin);
    printf("Enter Withdrawal Amount : ");
    scanf("%f", &acc.amount);
    sentbytes= sendto(sockfd,&acc, sizeof(acc),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr) );
   
    if (sentbytes == -1)
    {
        close(sockfd);
        exit(0);
    }
    char str[20];
    actuallen = sizeof(serveraddr);
     recedbytes= recvfrom(sockfd, &str, sizeof(str),0,(struct sockaddr*)&serveraddr,&actuallen);
   
    printf("\n SERVER RESPONSE:%s\n", str);
    close(sockfd);

    return 0;
}