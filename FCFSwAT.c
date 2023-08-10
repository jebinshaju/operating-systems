#include<stdio.h>

struct process
{	int pid,bt,at,ct,tt,wt,comp;
}P[20];

void main()
{	int n,i,j,time=0,x=1;	
	printf("Enter no of process");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{	printf("Enter process id, burst time and arrival time for %dth process",i+1);
		scanf("%d",&P[i].pid);
		scanf("%d",&P[i].bt);
		scanf("%d",&P[i].at);
		P[i].comp=-1;
	}
	
	for (i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	if (P[j].at<=time && P[j].comp==-1)
			{	P[j].ct=time+P[j].bt;
				P[j].tt=P[j].ct-P[j].at;
				P[j].wt=P[j].tt-P[j].bt;
				time+=P[j].bt;
				P[j].comp=x; //X shows which one completed first,second,third...
				x++;
			}
		}
	}
	
	printf("-------------------------------------------\n");
	printf("|  ID  |  BT  |  AT  |  CT  |  TT  |  WT  |\n");  
	printf("-------------------------------------------\n");
	for(i=1;i<n+1;i++)
	{	for(j=0;j<n;j++)
		{	if(P[j].comp == i)
			{	printf("|  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |\n",P[j].pid,P[j].bt,P[j].at,P[j].ct,P[j].tt,P[j].wt);
				break;
			}
		}
	}
}
	
			
			
			
			
			
			
