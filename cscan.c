#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,d[200],y[100],head,hm=0,cy,temp;
	printf("Enter the number of requests: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the Request %d:",i+1);
		scanf("%d",&d[i]);
	}
	printf("Enter the head position: ");
	scanf("%d",&head);
	
	printf("Enter the number of cylinders: ");
	scanf("%d",&cy);
	
	for (i=0;i<n-1;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if (d[j]>d[j+1])
			{
				temp=d[j];
				d[j]=d[j+1];
				d[j+1]=temp;
			}	
		}
		
	}
	
	
	
	int k=0;
	for(i=0;i<n;i++)
	{
		if(d[i]<head)
		{
			y[k]=d[i];
			k++;
		}
	}
	 
	for (i=0;i<k-1;i++)
	{
		for (j=0;j<k-i-1;j++)
		{
			if (y[j]<y[j+1])
			{
				temp=y[j];
				y[j]=y[j+1];
				y[j+1]=temp;
			}	
		}
		
	}
	
	
	int sweeps = abs(cy-head)+(cy)+y[0];
	printf("Number of sweeps: %d\n",sweeps);
	
	for(i=0;i<n;i++)
	{
		if(d[i]>head)
		{
			printf("%d,",d[i]);
		}
	}
	for (i=0;i<k-1;i++)
	{
		for (j=0;j<k-i-1;j++)
		{
			if (y[j]>y[j+1])
			{
				temp=y[j];
				y[j]=y[j+1];
				y[j+1]=temp;
			}	
		}
		
	}
	for(i=0;i<k;i++)
	{
		if(y[i]<head)
		{
			printf("%d,",y[i]);
		}
	}
	
	
	
	
	
}
