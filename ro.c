#include <stdio.h>
struct process
{
	int pid;
	int TAT;
	int BT;
	int bt;
	int WT;
} p[10];
int main()
{
	int i, n, ts, x, y, wt, tat;
	double avgwt, avgtat;
	printf("Enter the no.of processes : ");
	scanf("%d", &n);
	printf("Enter the time quantum : ");
	scanf("%d", &ts);

	for (i = 0; i < n; i++)
	{
		printf("Enter the process ID : ");
		scanf("%d", &p[i].pid);
		printf("Enter the burst time : ");
		scanf("%d", &p[i].BT);
		p[i].bt = p[i].BT;
	}
	x = 0, y = 0, i = 0;
	while (1)
	{
		if (p[i].bt != 0)
		{
			if (p[i].bt >= ts)
			{
				x = x + ts;
				p[i].bt = p[i].bt - ts;
			}
			else
			{
				x = x + p[i].bt;
				p[i].bt = 0;
			}
			if (p[i].bt == 0)
			{
				p[i].TAT = x;
				y++;
				if (y == n)
					break;
			}
		}
		if (i == n - 1)
			i = 0;
		else
			i++;
	}
	for (i = 0; i < n; i++)
	{
		p[i].WT = p[i].TAT - p[i].BT;
	}
	printf("Process ID\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].pid, p[i].BT, p[i].TAT, p[i].WT);
		wt = wt + p[i].WT;
		tat = tat + p[i].TAT;
	}
	avgwt = (double)wt / n;
	avgtat = (double)tat / n;
	printf("Average waiting time is %.2f \n", avgwt);
	printf("Average turnaroundtime is %.2f\n", avgtat);

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



#include <stdio.h>

#define TIME_QUANTUM 2

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

// Enqueue a process into the ready queue
int enqueue(Process ready_queue[], int rear, Process process, int max_size) {
    // Check if the queue is full
    if ((rear + 1) % max_size == 0) {
        return rear; // Return the unchanged rear index
    }
    ready_queue[rear] = process; // Add process to the queue
    return (rear + 1) % max_size; // Return the updated rear index using modulo arithmetic
}

// Dequeue a process from the ready queue
Process dequeue(Process ready_queue[], int front, int rear, int max_size) {
    Process empty = { -1, 0, 0 };
    // Check if the queue is empty
    if (front == rear) {
        return empty; // Return an empty process
    }
    Process process = ready_queue[front]; // Get the process from the front of the queue
    return process;
}

// Implement the Round Robin scheduling algorithm
void roundRobin(Process processes[], int n) {
    int current_time = 0;
    int front = 0, rear = 0;
    int max_size = n;
    Process ready_queue[n];
    int time_quantum = TIME_QUANTUM;

    while (1) {
        int all_finished = 1;

        // Check if all processes have finished executing
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                all_finished = 0;

                if (processes[i].remaining_time > time_quantum) {
                    current_time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    printf("Process %d completed at time %d\n", processes[i].id, current_time);
                }

                // Enqueue the process back into the ready queue
                rear = enqueue(ready_queue, rear, processes[i], max_size);
            }
        }

        if (all_finished) {
            break; // Exit the loop if all processes have finished
        }

        // Execute processes in round-robin order
        while (front != rear) {
            // Dequeue a process from the front of the ready queue
            Process current_process = dequeue(ready_queue, front, rear, max_size);
            front = (front + 1) % max_size; // Update the front index using modulo arithmetic
            if (current_process.id != -1) {
                // Enqueue the dequeued process back into the ready queue
                rear = enqueue(ready_queue, rear, current_process, max_size);
                break;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    // Input burst times for each process
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].id = i;
    }

    // Call the Round Robin scheduling algorithm
    roundRobin(processes, n);

    return 0;
}

*/