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
		scanf("%d",&d[i]);
	}
	printf("Enter the head position: ");
	scanf("%d",&head);
	
	for(i=0;i<n;i++)
	{
		hm=hm+abs(d[i]-head);
		head=d[i];
	}
	printf("\nNumber of sweeps: %d",hm);
	
}
