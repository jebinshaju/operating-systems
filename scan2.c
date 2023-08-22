#include <stdio.h>

int main()
{
	int n, i, j, d[200], head, hm = 0, cy, temp;
	printf("Enter the number of requests: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Enter the Request %d:", i + 1);
		scanf("%d", &d[i]);
	}
	printf("Enter the head position: ");
	scanf("%d", &head);

	printf("Enter the number of cylinders: ");
	scanf("%d", &cy);

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (d[j] > d[j + 1])
			{
				temp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = temp;
			}
		}
	}

	int sweeps = (cy - head) + (cy - d[0]);
	printf("Number of sweeps: %d\n", sweeps);
	printf("sweep sequence");
	for (i = 0; i < n; i++)
	{
		if (d[i] > head)
		{
			printf("%d,", d[i]);
		}
	}

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (d[j] < d[j + 1])
			{
				temp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (d[i] < head)
		{
			printf("%d,", d[i]);
		}
	}
}
/*
Enter the number of requests: 8
Enter the Request 1:98
Enter the Request 2:183
Enter the Request 3:37
Enter the Request 4:122
Enter the Request 5:14
Enter the Request 6:124
Enter the Request 7:65
Enter the Request 8:67
Enter the head position: 50
Enter the number of cylinders: 200
Number of sweeps: 336
sweep sequence65,67,98,122,124,183,37,14,

