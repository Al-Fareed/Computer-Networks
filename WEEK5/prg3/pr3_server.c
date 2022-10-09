//Author Name:Ashuthosh S Padmashali
//Reg No:210970052
//Program Name:Program to implement the shared memory by performing the transpose of the matrix
//
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

struct matchcity
{
	char state[20];
	char capital[20];
	int flag;
};

int main()
{
	struct matchcity *m;
	char *values[][40]={
		{"Karnataka","Banglore"},
		{"Tamilnadu","chennai"},
		{"Andhrapradesh","hydrabad"},
		{"Rajasthan","Jaipur"},
		{"Gujarath","Gandhinagar"}
	};
	int shmid;
	int key=ftok("city",37);
	shmid=shmget(key,1024,0666|IPC_CREAT);
	m=shmat(shmid,NULL,0);
	for(int i=0;i<5;i++)
	{
			if(((*m->state)==*values[i][0]) &&((*m->capital)==*values[i][1]))
			{

				m->flag=1;
				break;
			}
			else
			{
				m->flag=0;
			}
	}
	return 0;
}
