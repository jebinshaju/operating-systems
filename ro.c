#include <stdio.h>
struct Process
{
	int id;         // Process ID
	int turnaround; // Turnaround Time
	int burst_time; // Burst Time (initial)
	int remaining_burst_time; // Remaining Burst Time
	int waiting_time; // Waiting Time
} processes[10];     // Array of processes

int main()
{
	int i, num_processes, time_quantum, current_time = 0, completed_processes = 0, total_waiting_time = 0, total_turnaround_time = 0;
	double avg_waiting_time, avg_turnaround_time;

	// Input number of processes and time quantum
	printf("Enter the number of processes: ");
	scanf("%d", &num_processes);
	printf("Enter the time quantum: ");
	scanf("%d", &time_quantum);

	// Input process details
	for (i = 0; i < num_processes; i++)
	{
		printf("Enter the Process ID: ");
		scanf("%d", &processes[i].id);
		printf("Enter the Burst Time: ");
		scanf("%d", &processes[i].burst_time);
		processes[i].remaining_burst_time = processes[i].burst_time; // Initialize remaining burst time
	}

	// Perform Round Robin Scheduling
	i = 0;
	while (1)
	{
		if (processes[i].remaining_burst_time != 0)
		{
			if (processes[i].remaining_burst_time >= time_quantum)
			{
				current_time = current_time + time_quantum; // Increment time by time quantum
				processes[i].remaining_burst_time = processes[i].remaining_burst_time - time_quantum; // Reduce remaining burst time
			}
			else
			{
				current_time = current_time + processes[i].remaining_burst_time; // Increment time by remaining burst time
				processes[i].remaining_burst_time = 0; // Process is done
			}

			if (processes[i].remaining_burst_time == 0)
			{
				processes[i].turnaround = current_time; // Set turnaround time for the process
				completed_processes++; // Increment completed process count
				if (completed_processes == num_processes)
					break; // All processes are completed
			}
		}

		if (i == num_processes - 1)
			i = 0; // Loop back to the first process
		else
			i++; // Move to the next process
	}

	// Calculate waiting time for each process and total times
	for (i = 0; i < num_processes; i++)
	{
		processes[i].waiting_time = processes[i].turnaround - processes[i].burst_time;
		total_waiting_time = total_waiting_time + processes[i].waiting_time;
		total_turnaround_time = total_turnaround_time + processes[i].turnaround;
	}

	// Calculate average waiting time and average turnaround time
	avg_waiting_time = (double)total_waiting_time / num_processes;
	avg_turnaround_time = (double)total_turnaround_time / num_processes;

	// Display process details and average times
	printf("Process ID\tBurst Time\tTurnaround Time\tWaiting Time\n");
	for (i = 0; i < num_processes; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].turnaround, processes[i].waiting_time);
	}

	printf("Average Waiting Time is %.2f\n", avg_waiting_time);
	printf("Average Turnaround Time is %.2f\n", avg_turnaround_time);

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

/*

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