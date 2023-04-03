#include<stdio.h>
struct process
{
	int pid;
	int bt;
	int wt;
	int tt;
	int prio;
	
}a[20],temp;
int n;


void priority()
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
	printf("Process ID\t\tPriority\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",a[i].pid,a[i].prio,a[i].bt,a[i].wt,a[i].tt);
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
		printf("Enter the priority : ");
		scanf("%d",&a[i].prio);
	}
	for(i=0;i<n-1;i++)
	{
			for(j=i+1;j<n;j++)
			{
				if(a[i].prio>a[j].prio)
				{
					temp=a[i];
					
					a[i]=a[j];
					a[j]=temp;
				}
			}
	}
	priority();
	display();
}

/*

Enter the number of process: 3
Enter the PROCESS ID : 1
Enter the BURST TIME : 3
Enter the priority : 9
Enter the PROCESS ID : 2
Enter the BURST TIME : 5
Enter the priority : 7
Enter the PROCESS ID : 3
Enter the BURST TIME : 3
Enter the priority : 8

P-ID   BT   WT   TT
2     5     0    5
3     3     5    8
1     3     8    11

Average waiting time : 4.33 
Average turn around time : 8.00 

|---------------|---------------|---------------|
|	2	|	3	|	1	|
|---------------|---------------|---------------|
0		5		8		11


*/
