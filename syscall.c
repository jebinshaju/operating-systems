#include<stdio.h>
#include<unistd.h>
 int main()
 {
 	int value;
 	value = fork();
 	printf("ID : %d\n",value);
 	if (value==0)
 	{
 		printf("Child ID: %d\n",getpid());
 		printf("Parent ID: %d\n",getppid());
 	}
 	else if (value > 0)
 	{
 		wait();
 		printf("parentID: %d\n",getpid());
 		printf("Parent's parent ID: %d\n",getppid());
 	}
 	else
 	{
 		printf("Not created");
 		exit(0);
 	}
 }
 
/*
ID : 4264
ID : 0
Child ID: 4264
Parent ID: 4263
parentID: 4263
Parent's parent ID: 3472
*/
