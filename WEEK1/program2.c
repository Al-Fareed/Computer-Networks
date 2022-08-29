//Name:Al-Fareed
//Reg No:210970049
//Program to read a file name from the keyboard by the parent and child process uses the file name and reads first 10 characters from the file. 
//--------------------------------------------------------
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	char buf;
	int i=0,file;
	int count=0;
	char rdFile[25];
	printf("Enter the name of the file:");
	scanf("%s",rdFile);
	int pid=fork();
	if(pid>0){
	file=open(rdFile,O_RDONLY);
	printf("Text in the file %s is ",rdFile);
	while(read(file,&buf,1)&&count<10)
	{
		printf("%c",buf);
		count++;
	}}
printf("\n");
return 0;
}
