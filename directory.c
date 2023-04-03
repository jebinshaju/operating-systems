#include<dirent.h>
#include<stdio.h>

struct dirent *ptr;
void main()
{
	char b[10];
	DIR *dirptr;
	printf("Enter the directory name: ");
	scanf("%s",&b);
	dirptr = opendir(b);
	
	if(dirptr == NULL)
	{
		printf("Error!");
	}
	else
	{
		while(ptr = readdir(dirptr))
		{
			printf("Name:%s\n",ptr->d_name);
			printf("type:%d\n",ptr->d_type);
			printf("File no:%d\n",ptr->d_fileno);
		}
	}
}
