//Author Name:Ashuthosh S Padmashali
//Regnno:210970052
//Program Name:program to input a capital of the respective state and share it to the server, server finds it in the database and matches it ..perfrom using shared memory
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

struct matchcity
{
	char state[20];
	char capital[20];
	int flag;
};

int main()
{
	struct matchcity *m;
	int shmid,null;
	int key=ftok("city",37);
	shmid=shmget(key,1024,0666|IPC_CREAT);
	m=shmat(shmid,NULL,0);
	printf("Enter the State to searched:\n");
	scanf("%s",m->state);
	printf("\nEnter the respective capital of the state that has been entered:(Press 0 that the value to be stopped:)\n");
	scanf("%s",m->capital);
	scanf("%d",&null);
	if(m->flag==0)
		printf("\n The State and the capital are not  found in the database");
	else
		printf("\n The State and Capital are present in the database");
	return 0;
}
