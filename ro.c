#include <stdio.h>
struct process
{
    int pid;
    int TAT;
    int BT;
    int bt;
    int WT;
}p[10];
int main() 
{
    int i,n,ts,x,y,wt,tat;
    double avgwt,avgtat;
    printf("Enter the no.of processes : ");
    scanf("%d",&n);
    printf("Enter the time quantum : ");
    scanf("%d",&ts);
    
    for(i=0;i<n;i++)
    {
        printf("Enter the process ID : ");
        scanf("%d",&p[i].pid);
        printf("Enter the burst time : ");
        scanf("%d",&p[i].BT);
		p[i].bt=p[i].BT;        
    }
    x=0,y=0,i=0;
    while(1)
    {
		if(p[i].bt!=0)
		{
			if(p[i].bt>=ts)
			{
				x=x+ts;
				p[i].bt=p[i].bt-ts;
			}
			else
			{
				x=x+p[i].bt;
				p[i].bt=0;
			}
			if(p[i].bt==0)
			{
				p[i].TAT=x;
				y++;
				if(y==n)
					break;
			}
    	}
		if(i==n-1)	
			i=0;
		else
			i++;
	}
	for(i=0;i<n;i++)
	{
		p[i].WT=p[i].TAT-p[i].BT;
	}
	printf("Process ID\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",p[i].pid,p[i].BT,p[i].TAT,p[i].WT);
		wt=wt+p[i].WT;
		tat=tat+p[i].TAT;
	}
	avgwt=(double)wt/n;
	avgtat=(double)tat/n;
	printf("Average waiting time is %.2f \n",avgwt);
	printf("Average turnaroundtime is %.2f\n",avgtat);
	
	/*for(i=0;i<n;i++)
	{
		printf("|---------------");
		
	}
	printf("|\n");
	for(i=0;i<n;i++)
	{
		printf("|\t%d\t",p[i].pid);
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
		printf("\t\t%d",p[i].TAT);
		
	}
	printf("\n");
	*/
    return 0;
}

/*
Enter the no.of processes : 3
Enter the time quantum : 2
Enter the process ID : 1
Enter the burst time : 4
Enter the process ID : 2
Enter the burst time : 7
Enter the process ID : 3
Enter the burst time : 9
Process ID		Burst Time		Turnaround Time		Waiting Time
1			4			8			4
2			7			17			10
3			9			20			11
Average waiting time is 8.33 
Average turnaroundtime is 15.00
*/
