
#include <stdio.h>
int main()
{
	int n, m, i, j, k;
	printf("Enter the number of processes:");
	scanf("%d",&m);
	printf("Enter the number of resources:");
	scanf("%d",&n);
	
	int max[m][n],alloc[m][n],avail[n];
	
	int f[m], ans[m], ind = 0;

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter the Max %d:",j+1);
			scanf("%d",&max[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter the Allocation %d:",j+1);
			scanf("%d",&alloc[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",max[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",alloc[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		printf("Enter the number of available resources for process %d:",i+1);
		scanf("%d",&avail[i]);
	}
   
 
	
	for (k = 0; k < m; k++)
	{
		f[k] = 0;
	}
	int need[m][n];
	for (i = 0; i < m; i++) 
	{
		for (j = 0; j < n; j++)
			{
				need[i][j] = max[i][j] - alloc[i][j];
			}
	}
	printf("\n");
	printf("NEED Table\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d \t",need[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	int y = 0;
	for (k = 0; k < 5; k++)
	{
		for (i = 0; i < m; i++)
		{
			if (f[i] == 0)
			{
 				int flag = 0;
				for (j = 0; j < n; j++)
				{
					if (need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}
 
				if (flag == 0)
				{
					ans[ind++] = i;
					for (y = 0; y < n; y++)
					{
						avail[y] += alloc[i][y];
                    			}
					f[i] = 1;
                		}
            		}
        	}
    	}
   
int flag = 1;
for(int i=0;i<m;i++)
{
	if(f[i]==0)
	{
		flag=0;
		printf("The following system is not safe");
		break;
	}
}
     
if(flag==1)
{
	printf("The SAFE Sequence\n");
	for(i = 0; i < m - 1; i++)
	{
		printf(" P%d ->", ans[i]);
	}
	printf(" P%d", ans[n - 1]);
}
     
 
return (0);
 
 
}




 
/*

Enter the number of processes:5
Enter the number of resources:3
Enter the Max 1:7
Enter the Max 2:5
Enter the Max 3:3

Enter the Max 1:3
Enter the Max 2:2
Enter the Max 3:2

Enter the Max 1:9
Enter the Max 2:0
Enter the Max 3:2

Enter the Max 1:2
Enter the Max 2:2
Enter the Max 3:2

Enter the Max 1:4
Enter the Max 2:3
Enter the Max 3:3

Enter the Allocation 1:0
Enter the Allocation 2:1
Enter the Allocation 3:0

Enter the Allocation 1:2
Enter the Allocation 2:0
Enter the Allocation 3:0

Enter the Allocation 1:3
Enter the Allocation 2:0
Enter the Allocation 3:2

Enter the Allocation 1:2
Enter the Allocation 2:1
Enter the Allocation 3:1

Enter the Allocation 1:0
Enter the Allocation 2:0
Enter the Allocation 3:2

7	5	3	
3	2	2	
9	0	2	
2	2	2	
4	3	3	

0	1	0	
2	0	0	
3	0	2	
2	1	1	
0	0	2	
Enter the number of available resources for process 1:3
Enter the number of available resources for process 2:3
Enter the number of available resources for process 3:2

NEED Table
7 	4 	3 	
1 	2 	2 	
6 	0 	0 	
0 	1 	1 	
4 	3 	1 	

The SAFE Sequence
 P1 -> P3 -> P4 -> P0 -> P4
     */
