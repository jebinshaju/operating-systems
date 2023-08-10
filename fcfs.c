#include <stdio.h>
struct shedule
{
	int pid;
	int bt;
	int wt;
	int tt;

} a[20];
int n;

void fcfs()
{
	int i;

	for (i = 0; i < n; i++)
	{
		a[i].tt = a[i].bt + a[i].wt;
		a[i + 1].wt = a[i].tt;
	}
}

void display()
{
	int i;
	float avg_wt = 0, avg_tt = 0;
	printf("\n");
	printf("P-ID   BT   WT   TT\n");
	for (i = 0; i < n; i++)
	{
		printf("%d     %d     %d    %d\n", a[i].pid, a[i].bt, a[i].wt, a[i].tt);
		avg_wt = avg_wt + a[i].wt;
		avg_tt = avg_tt + a[i].tt;
	}
	avg_wt = avg_wt / n;
	avg_tt = avg_tt / n;
	printf("\nAverage waiting time : %.2f \nAverage turn around time : %.2f \n", avg_wt, avg_tt);
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("|---------------");
	}
	printf("|\n");
	for (i = 0; i < n; i++)
	{
		printf("|\t%d\t", a[i].pid);
	}
	printf("|\n");
	for (i = 0; i < n; i++)
	{
		printf("|---------------");
	}
	printf("|\n");
	printf("0");
	for (i = 0; i < n; i++)
	{
		printf("\t\t%d", a[i].tt);
	}
	printf("\n");
}

void main()
{
	int i;
	a[0].wt = 0;
	printf("Enter the number of process: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter the PROCESS ID : ");
		scanf("%d", &a[i].pid);
		printf("Enter the BURST TIME : ");
		scanf("%d", &a[i].bt);
	}
	fcfs();
	display();
}

/*

Enter the number of process: 4
Enter the PROCESS ID : 1
Enter the BURST TIME : 5
Enter the PROCESS ID : 2
Enter the BURST TIME : 6
Enter the PROCESS ID : 3
Enter the BURST TIME : 7
Enter the PROCESS ID : 4
Enter the BURST TIME : 8

P-ID   BT   WT   TT
1     5     0    5
2     6     5    11
3     7     11    18
4     8     18    26

Average waiting time : 8.500000
Average turn around time : 15.000000

|---------------|---------------|---------------|---------------|
|	1	|	2	|	3	|	4	|
|---------------|---------------|---------------|---------------|
0		5		11		18		26

*/
