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

	int clientSocket, ret;
	struct sockaddr_in serverAddr;

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Client Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Connected to Server.\n");

	struct ops opsc;

	printf("Enter First Operand: \t");
	scanf("%d", &opsc.op1);
	printf("Enter Second Operand: \t");
	scanf("%d", &opsc.op2);
	fflush(stdin);
	printf("Enter Operator (/,*,+,-): ");
	scanf(" %c", &opsc.optr);
	
	write(clientSocket, (struct ops*) &opsc, sizeof(opsc));


	if(recv(clientSocket, (struct ops*) &opsc, sizeof(opsc), 0) < 0){
		printf("[-]Error in receiving data.\n");
	}
	else
	{
		printf("Answer: \t%f\n", opsc.ans);
	}

	return 0;
}
