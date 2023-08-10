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
