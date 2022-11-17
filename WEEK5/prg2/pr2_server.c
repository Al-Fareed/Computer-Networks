#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

struct armstrong
{
	int num,n,rem;
	int res,flag;
};
int main()
{
	struct armstrong *a;
	int shmid;
	int key=ftok("armstrong",35);
	shmid=shmget(key,1024,0666|IPC_CREAT);
	a=shmat(shmid,NULL,0);
	printf("%d\n",a->num);
	a->n=a->num;
	a->flag=0;
	a->res=0;
	while(a->n!=0)
	{
		a->rem=a->n%10;
		a->res=a->res+(a->rem*a->rem*a->rem);
		a->n=a->n/10;
	}
	printf("\n res %d:",a->res);
	if(a->res==a->num)
		a->flag=0;
	else
		a->flag=1;
	return  0;

}
