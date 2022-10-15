#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAXSIZE 50
struct ip_sol
{
    char class[15];
    char mask[16];
};

int main()
{
    int sockfd, newsockfd, retval;
    socklen_t actuallen;

    int recedbytes, sentbytes;
    struct sockaddr_in serveraddr, clientaddr;
    char buff[MAXSIZE];
    int a = 0;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1)
    {
        printf("\n Socket creation error");
        exit(-1);
    }
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3387);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    retval = bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (retval == -1)
    {
        printf("Binding Error");
        close(sockfd);
        exit(0);
    }
 

    actuallen = sizeof(clientaddr);
    recedbytes = recvfrom(sockfd, buff ,sizeof(buff),0,(struct sockaddr*)&clientaddr,&actuallen);
    int no, n= 0;
    struct ip_sol res;

    while (buff[n] != '.'){
        no = no * 10 + (buff[n] - '0');
        n++;
    }
    if (no >= 0 && no < 128) {
        strcpy(res.class, "class A");
        strcpy(res.mask, "255.0.0.0");
    } else if (no >= 128 && no < 192) {
        strcpy(res.class, "class B");
        strcpy(res.mask, "255.255.0.0");
    } else if (no >= 192 && no < 224) {
        strcpy(res.class, "class C");
        strcpy(res.mask, "255.255.255.0");
    } else if (no >= 224 && no < 240) {
        strcpy(res.class, "class D");
        strcpy(res.mask, "255.255.255.255");
    } else {
        strcpy(res.class, "class E");
        strcpy(res.mask, "255.255.255.255");
    } 
    sentbytes=sendto(sockfd , &res, sizeof(res),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
    if (sentbytes == -1)
    {
        close(sockfd);
        close(newsockfd);
        exit(0);
    } 

    close(newsockfd);
    close(sockfd);

    return 0;
}