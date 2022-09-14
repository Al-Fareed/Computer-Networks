#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[] )  {  
    int num1,num2;
    int pid=fork();
    if(pid==0){
   if(argc < 4){  
      printf("Passed arguments in command line are not sufficient.\n");  
   }  
   else{  
      printf("Operation to be performed is: %s\n", argv[1]);  
      printf("First integer is: %s\n", argv[2]);  
      printf("Second integer is: %s\n", argv[3]);  
       num1=atoi(argv[2]);
       num2=atoi(argv[3]);
      switch (*argv[1])
      {
      case '+': printf("Sum of given two integers is:%d\n",(num1+num2));
                break;
      case '-': printf("Difference of given two integers is:%d\n",(num1-num2));
                break;
      case '*': printf("Product of given two integers is:%d\n",(num1*num2));
                break;
      case '/': printf("Division of given two integers is:%d\n",(num1/num2));
                break;
      
      default:printf("Given operation is not valid\n");
      }
   }  
    }
    else{
        printf("Child process not created!");
    }
   return 0;
}  