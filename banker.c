#include <stdio.h>

int main()
{
    int num_processes, num_resources, i, j, k;
    printf("Enter the number of processes:");
    scanf("%d", &num_processes);
    printf("Enter the number of resources:");
    scanf("%d", &num_resources);

    int max[num_processes][num_resources], alloc[num_processes][num_resources], available[num_resources];
    int finished[num_processes], safe_sequence[num_processes], index = 0;

    // Input Max matrix
    for (i = 0; i < num_processes; i++)
    {
        for (j = 0; j < num_resources; j++)
        {
            printf("Enter the Max for Process %d Resource %d:", i + 1, j + 1);
            scanf("%d", &max[i][j]);
        }
        printf("\n");
    }

    // Input Allocation matrix
    for (i = 0; i < num_processes; i++)
    {
        for (j = 0; j < num_resources; j++)
        {
            printf("Enter the Allocation for Process %d Resource %d:", i + 1, j + 1);
            scanf("%d", &alloc[i][j]);
        }
        printf("\n");
    }

    // Input available resources
    for (i = 0; i < num_resources; i++)
    {
        printf("Enter the number of available resources for resource %d:", i + 1);
        scanf("%d", &available[i]);
    }

    // Calculate Need matrix
    int need[num_processes][num_resources];
    for (i = 0; i < num_processes; i++)
    {
        for (j = 0; j < num_resources; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Safety algorithm
    int completed;
    for (k = 0; k < num_processes; k++)
    {
        finished[k] = 0;
    }

    for (k = 0; k < num_processes; k++)
    {
        for (i = 0; i < num_processes; i++)
        {
            if (finished[i] == 0)
            {
                int can_allocate = 1;
                for (j = 0; j < num_resources; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        can_allocate = 0;
                        break;
                    }
                }

                if (can_allocate)
                {
                    safe_sequence[index++] = i;
                    for (j = 0; j < num_resources; j++)
                    {
                        available[j] = available[j] + alloc[i][j];
                    }
                    finished[i] = 1;
                }
            }
        }
    }

    // Check if a safe sequence was found
    int is_safe = 1;
    for (i = 0; i < num_processes; i++)
    {
        if (finished[i] == 0)
        {
            is_safe = 0;
            printf("The system is not safe\n");
            break;
        }
    }

    // Display safe sequence
    if (is_safe)
    {
        printf("The SAFE Sequence\n");
        for (i = 0; i < num_processes - 1; i++)
        {
            printf(" P%d ->", safe_sequence[i]);
        }
        printf(" P%d\n", safe_sequence[num_processes - 1]);
    }

    return 0;
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
