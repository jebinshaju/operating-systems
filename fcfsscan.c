#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,d[200],head,hm=0;
	printf("Enter the number of requests: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{ 
		printf("Enter the Request %d:",i+1);
		scanf("%d, ",&d[i]);
	}
	printf("Enter the head position: ");
	scanf("%d",&head);
	
	for(i=0;i<n;i++)
	{
		hm=hm+abs(d[i]-head);
		head=d[i];
		printf("%d   ",d[i]);
	}
	printf("\nNumber of sweeps: %d",hm);
	
}

/*
Enter the number of requests: 8
Enter the Request 1:98
Enter the Request 2:183
Enter the Request 3:37
Enter the Request 4:122
Enter the Request 5:14
Enter the Request 6:124
Enter the Request 7:65
Enter the Request 8:67
Enter the head position: 50
98   183   37   122   14   124   65   67   
Number of sweeps: 643
*/
