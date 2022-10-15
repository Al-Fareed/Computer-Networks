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
struct account{
    unsigned long int accno;
    int pin;
    float amount;
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
   
    struct account rcvAcc;
    actuallen = sizeof(clientaddr);
     recedbytes = recvfrom(sockfd,  &rcvAcc, sizeof(rcvAcc),0,(struct sockaddr*)&clientaddr,&actuallen);
    
    if (recedbytes == -1) {
        close(sockfd);
        close(newsockfd);
        exit(0);
    } 
    struct account acc[5];
    
    char str[100];

    acc[0].accno = 111;
    acc[0].pin = 123;
    acc[0].amount = 1000;
    acc[1].accno = 222;
    acc[1].pin = 124;
    acc[1].amount = 2000;
    acc[2].accno = 333;
    acc[2].pin = 125;
    acc[2].amount = 3000;
    acc[3].accno = 444;
    acc[3].pin = 126;
    acc[3].amount = 4000;
    acc[4].accno = 555;
    acc[4].pin = 127;
    acc[4].amount = 5000;

    int flag = 0;

    for (int i = 0; i < 5; i++)
    {
        if (acc[i].accno == rcvAcc.accno)
        {
            if (acc[i].pin == rcvAcc.pin)
            {
                if ((acc[i].amount - rcvAcc.amount) >= 1000){
                    acc[i].amount -= rcvAcc.amount;
                    sprintf(str, "AMMOUNT DEDUCTED : %.2f\nBALANCE : %.2f ", rcvAcc.amount, acc[i].amount);
                } else {
                    strcpy(str, "INSUFICENT BALANCE");
                }
            }
            else {
                strcpy(str, "INVALID PIN");
            }
            flag = 1;
            break;
        }
    }
    if (flag == 0){
        strcpy(str, "INVALID ACCOUNT NO");
    }
    sentbytes=sendto(sockfd , &str, sizeof(str),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
   
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