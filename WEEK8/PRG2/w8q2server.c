#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

struct ops
{
	int op1, op2;
	char optr;
	float ans;
};

int main(){

	struct ops opss;

	int sockfd, ret;
	struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = bind(sockfd, (struct sockaddr*)&serverAddr,sizeof(serverAddr));
	if(ret < 0)
	{
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bind to port %d\n", 4444);

	if(listen(sockfd, 10) == 0)
	{
		printf("[+]Listening....\n");
	}
	else
	{
		printf("[-]Error in binding.\n");
	}


	while(1)
	{
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0)
		{
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		if((childpid = fork()) == 0)
		{
			close(sockfd);
		}
		
		recv(newSocket, &opss, sizeof(opss), 0);
		switch(opss.optr)
		{
			case '/':
				opss.ans = opss.op1 / opss.op2;
				break;
			case '*':
				opss.ans = opss.op1 * opss.op2;
				break;
			case '+':
				opss.ans = opss.op1 + opss.op2;
				break;
			case '-':
				opss.ans = opss.op1 - opss.op2;
				break;
		}
		send(newSocket, &opss, sizeof(opss), 0);
				
	}

	close(newSocket);


	return 0;
}
