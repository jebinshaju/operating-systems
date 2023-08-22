#include<stdio.h>
struct block
{
	int id;
	int size;
	int alloc;
}B[10];
struct Process
{
	int id;
	int size;
	int blockno;
	int frees;
}P[10];

void sort(int n)
{
	int i,j;
	struct block temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(B[i].size>B[j].size)
			{
				temp=B[i];
				B[i]=B[j];
				B[j]=temp;
			}
		}
	}
}	
int main()
{
	int m,n,i,j;
	printf("Enter the number of Blocks: ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		B[i].id=i+1;
		printf("enter the size of block%d:",i+1);
		scanf("%d",&B[i].size);
		B[i].alloc=0;
	}
	printf("enter the number of process");
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		P[j].id=j+1;
		printf("enter the size of process%d: ",j+1);
		scanf("%d",&P[j].size);
		P[j].blockno=0;
	}
	for(i=0;i<n;i++)
	{
		sort(m);
		for(j=0;j<m;j++)
		{
			if(B[j].alloc!=1 && B[j].size>=P[i].size)
			{
				
				P[i].blockno=B[j].id;
				B[j].size=B[j].size-P[i].size;
				P[i].frees=B[j].size;
				P[i].frees=B[j].size;
				if(B[j].size==0)
					B[j].alloc=1;
					break;
					
			}
		}
		if(P[i].blockno==0)
			printf("allocation not possible");
		
	}
	printf("\nP_id\tsize\tBlockno.\tfree size\n");
	for(i=0;i<n;i++)
	{
	
		printf("\n%d\t%d\t%d\t\t%d\n",P[i].id,P[i].size,P[i].blockno,P[i].frees);
	}
		
}
/*
Enter the number of Blocks: 5
enter the size of block1:20
enter the size of block2:100
enter the size of block3:40
enter the size of block4:200
enter the size of block5:10
enter the number of process4
enter the size of process1: 90
enter the size of process2: 50
enter the size of process3: 30
enter the size of process4: 40

P_id	size	Blockno.	free size

1	90	2		10

2	50	4		150

3	30	3		10

4	40	4		110

