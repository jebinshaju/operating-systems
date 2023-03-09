#include<stdio.h>
struct process
{
	int pid;
	int bt;
	int wt;
	int tt;
	
}a[20],temp;
int n;


void sjf()
{
	int i;
	
	for(i=0;i<n;i++)
	{
		a[i].tt = a[i].bt + a[i].wt;
		a[i+1].wt = a[i].tt;
		
	}
}

void display()
{
	int i;
	float avg_wt=0,avg_tt=0;
	printf("\n");
	printf("P-ID   BT   WT   TT\n");
	for(i=0;i<n;i++)
	{
		printf("%d     %d     %d    %d\n",a[i].pid,a[i].bt,a[i].wt,a[i].tt);
		avg_wt = avg_wt + a[i].wt;
		avg_tt = avg_tt +a[i].tt;
	}
	avg_wt= avg_wt/n;
	avg_tt= avg_tt/n;
	printf("\nAverage waiting time : %.2f \nAverage turn around time : %.2f \n",avg_wt,avg_tt);
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		printf("|---------------");
		
	}
	printf("|\n");
	for(i=0;i<n;i++)
	{
		printf("|\t%d\t",a[i].pid);
	}
	printf("|\n");
	for(i=0;i<n;i++)
	{
		printf("|---------------");
		
	}
	printf("|\n");
	printf("0");
	for(i=0;i<n;i++)
	{
		printf("\t\t%d",a[i].tt);
		
	}
	printf("\n");
	

}

void main()
{
	int i,j;
	
	a[0].wt=0;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the PROCESS ID : ");
		scanf("%d",&a[i].pid);
		printf("Enter the BURST TIME : ");
		scanf("%d",&a[i].bt);
		
	}
	for(i=0;i<n-1;i++)
	{
			for(j=i+1;j<n;j++)
			{
				if(a[i].bt>a[j].bt)
				{
					temp=a[i];
					
					a[i]=a[j];
					a[j]=temp;
				}
			}
	}
	sjf();
	display();
}

/*

Enter the number of process: 3
Enter the PROCESS ID : 1
Enter the BURST TIME : 9
Enter the PROCESS ID : 2
Enter the BURST TIME : 5
Enter the PROCESS ID : 3
Enter the BURST TIME : 8

P-ID   BT   WT   TT
2     5     0    5
3     8     5    13
1     9     13    22

Average waiting time : 6.000000 
Average turn around time : 13.333333 

|---------------|---------------|---------------|
|	2	|	3	|	1	|
|---------------|---------------|---------------|
0		5		13		22

*/
