//Author Name:Ashuthosh S Padmashali
//Regno:210970052
//Program Name: Program to check whether the given nunmber is armstrong number or not by making use of the shared memory
//
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>

struct armstrong
{
	int num,n,rem;
	int res,flag;
};

int main()
{
	struct armstrong *a;
	int shmid,null;
	int key=ftok("armstrong",35);
	shmid=shmget(key,1024,0666|IPC_CREAT);
	a=shmat(shmid,NULL,0);
	printf("Enter the Number to be checked whether it is armstrong number or not(press 0 to close the input):");
	scanf("%d",&a->num);
	scanf("%d",&null);
	if(a->flag ==0)
		printf("\nThe given number is a armstrong number");
	else
		printf("\nThe given number is a not armstrong number");
	return 0;
}
