#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100
struct process
{
	int process_id;
	int arrival_time;
	int burst_time;
	int waiting_time;
	int turn_around_time;
	int remaining_time;
};
int queue[N];
int front = 0, rear = 0;
struct process proc[N];
void push(int process_id)
{
	queue[rear] = process_id;
	rear = (rear+1)%N;
}
int pop()
{
	if(front == rear)
		return -1;
	int return_position = queue[front];
	front = (front +1)%N;
	return return_position;
}

int main()
{
	float wait_time_total = 0.0, tat = 0.0;
	int n,time_quantum;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		printf("Enter the Arrival Time for the Process%d : ",i+1);
		scanf("%d", &proc[i].arrival_time);
		printf("Enter the Burst Time for the Process%d : ",i+1);
		scanf("%d", &proc[i].burst_time);
		proc[i].process_id = i+1;
		proc[i].remaining_time = proc[i].burst_time;
	}
	printf("Enter time quantum: ");
	scanf("%d",&time_quantum);
	int time=0; 
	int processes_left=n;   
	int position=-1; 		
	int local_time=0; 

	for(int j=0; j<n; j++)
		if(proc[j].arrival_time == time)
			push(j);

	while(processes_left)
	{
		if(local_time == 0) 
		{
			if(position != -1)
				push(position);

			position = pop();
		}

		for(int i=0; i<n; i++)
		{
			if(proc[i].arrival_time > time)
				continue;
			if(i==position)
				continue;
			if(proc[i].remaining_time == 0)
				continue;

			proc[i].waiting_time++;
			proc[i].turn_around_time++;
		}

		if(position != -1)
		{
			proc[position].remaining_time--;
			proc[position].turn_around_time++;
			
			if(proc[position].remaining_time == 0)
			{
				processes_left--;
				local_time = -1;
				position = -1;
			}
		}
		else
			local_time = -1; 

		time++;
		local_time = (local_time +1)%time_quantum;
		for(int j=0; j<n; j++)
			if(proc[j].arrival_time == time)	
				push(j);
	}
	printf("\n");

	printf("Process\t\tArrival Time\tBurst Time\tWaiting time\tTurn around time\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t\t%d\t\t", proc[i].process_id, proc[i].arrival_time);
		printf("%d\t\t%d\t\t%d\n", proc[i].burst_time, proc[i].waiting_time, proc[i].turn_around_time);

		tat += proc[i].turn_around_time;
		wait_time_total += proc[i].waiting_time;
	}

	tat = tat/(1.0*n);
	wait_time_total = wait_time_total/(1.0*n);

	printf("\nAverage Waiting Time     : %f",wait_time_total);
	printf("\nAverage Turn Around Time : %f\n", tat);
}

/* OUTPUT

Enter the number of processes: 5
Enter the Arrival Time for the Process1 : 0
Enter the Burst Time for the Process1 : 5
Enter the Arrival Time for the Process2 : 1
Enter the Burst Time for the Process2 : 3
Enter the Arrival Time for the Process3 : 2
Enter the Burst Time for the Process3 : 1
Enter the Arrival Time for the Process4 : 3
Enter the Burst Time for the Process4 : 2
Enter the Arrival Time for the Process5 : 4
Enter the Burst Time for the Process5 : 3
Enter time quantum: 2

Process		Arrival Time	Burst Time	Waiting time	Turn around time
1		0		5		8		13
2		1		3		8		11
3		2		1		2		3
4		3		2		4		6
5		4		3		7		10

Average Waiting Time     : 5.800000
Average Turn Around Time : 8.600000
*/
