//Author Name:Ashuthosh S Padmashali
//Reg No:210970052
//Program Name: Program to implement the shared memory by perfroming the transpose of the matrix
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
	printf("The entered array elements are");
	for( int i=0;i<t->m;i++)
	{
		for(int j=0;j<t->n;j++)
		{
			printf("%d  ",t->a[i][j]);
		}
		printf("\n");
	}
	printf("\n Perfroming the transpose operations");
	for( int i=0;i<t->m;i++)
	{
		for(int j=0;j<t->n;j++)
		{
			t->trans[j][i]=t->a[i][j];
		}
	}

	return 0;
}
