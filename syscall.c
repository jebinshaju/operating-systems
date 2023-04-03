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
