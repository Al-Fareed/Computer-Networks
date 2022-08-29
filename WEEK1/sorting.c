//Program to accept arrays and sort
//----------------------------------------------
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int a[10];
	printf("Enter 10 array of numbers : ");
	for(int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("Enterd array numbers are : ");
	for(int i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	int pid=fork();
	if(pid>0)
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				if(a[i]<a[j])
				{
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		printf("\nAfter sorting : ");
		for(int i=0;i<10;i++)
		{
			printf("%d\t",a[i]);
		}
	printf("\n");
	}
	else
	{
		printf("\nChild process not created \n");
	}
}
