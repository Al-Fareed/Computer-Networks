//Reg No:210970049
//Program to accept an array before forking and search the array in child for an element accepted and display the result.
//--------------------------------------------------------
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	int a[10],srch;
	printf("Enter 10 number of arrays:");
	for(int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEntered number of arrays are : ");
	for(int i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	int pid=fork();
	printf("\nEnter the element to be searched : ");
	scanf("%d",&srch);
	if(pid>0)
	{
		for(int i=0;i<10;i++)
		{
			if(a[i]==srch)
			{
				printf("\nElement %d found at position %d:\n",srch,i);
			}
			else
			{
				printf("\nElement %d is not present in the array!");
			}
		}
	}
return 0;
}
