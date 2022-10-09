//Author Name:Ashuthosh  S PAdmashali
//Reg No: 210970052
//Program Name:Program to implement the shared memory by perfoming the transpose of the matrix
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

struct transpose
{
	int a[10][10];
	int m,n;
	int trans[10][10];
};

int main()
{
	struct transpose *t;
	int shmid;
	int key=ftok("array1",34);
	shmid=shmget(key,1024,0666|IPC_CREAT);
	t=shmat(shmid,NULL,0);
	printf("Enter the number of rows and colums of the matrix:");
	scanf("%d",&t->m);

	scanf("%d",&t->n);
	printf("\nEnter the array elements(enter one element extra and then run the server):\n");
	for(int i=0;i<t->m;i++)
	{
		for(int j=0;j<t->n;j++)
		{
			scanf("%d\n",&t->a[i][j]);
		}
	}
	printf("\nthe array elements :\n");
	for(int i=0;i<t->m;i++)
	{
		for(int j=0;j<t->n;j++)
		{
			printf("%d  ",t->a[i][j]);
		}
		printf("\n");
	}
	
	printf("\nthe transpose matrix are :\n");
	for(int i=0;i<t->m;i++)
	{
		for(int j=0;j<t->n;j++)
		{
			printf("%d  ",t->trans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
