#include<stdio.h>

// Structure to represent a memory block
struct block
{
	int id;        // Block identifier
	int size;      // Size of the block
	int alloc;     // Allocation status (0 - Not allocated, 1 - Allocated)
} B[10];          // Array of blocks with a maximum of 10 blocks

// Structure to represent a process
struct Process
{
	int id;        // Process identifier
	int size;      // Size of the process
	int blockno;   // Block number to which the process is allocated
	int frees;     // Free space remaining in the block after allocation
} P[10];           // Array of processes with a maximum of 10 processes

int main()
{
	int m, n, i, j;
	printf("Enter the number of Blocks: ");
	scanf("%d", &m);

	// Input block information
	for(i = 0; i < m; i++)
	{
		B[i].id = i + 1;
		printf("Enter the size of Block %d: ", i + 1);
		scanf("%d", &B[i].size);
		B[i].alloc = 0; // Initialize allocation status to not allocated
	}

	printf("Enter the number of Processes: ");
	scanf("%d", &n);

	// Input process information
	for(j = 0; j < n; j++)
	{
		P[j].id = j + 1;
		printf("Enter the size of Process %d: ", j + 1);
		scanf("%d", &P[j].size);
		P[j].blockno = 0; // Initialize block number to 0 (not allocated to any block)
	}

	// Allocation logic
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(B[j].alloc != 1 && B[j].size >= P[i].size)
			{
				P[i].blockno = B[j].id;          // Allocate process to the block
				B[j].size -= P[i].size;          // Update block size
				P[i].frees = B[j].size;          // Update free space in the block after allocation

				if(B[j].size == 0)
					B[j].alloc = 1; // Mark the block as allocated if it's fully used

				break; // Exit the loop after allocation
			}
		}
		if(P[i].blockno == 0)
			printf("Allocation not possible for Process %d\n", P[i].id);
	}

	// Output allocation results
	printf("\nP_id\tsize\tBlockno.\tfree size\n");
	for(i = 0; i < n; i++)
	{
		printf("%d\t%d\t%d\t\t%d\n", P[i].id, P[i].size, P[i].blockno, P[i].frees);
	}
}
