#include <stdio.h>
#include <stdlib.h>

struct sjf {
    int pid;
    int btime;
    int wtime;
    int ttime;
    int arrival_time; // New field for arrival time
};

int tottime, totwtime = 0;

void main() {
    int n, t;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct sjf p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter the burst time of process %d: ", p[i].pid);
        scanf("%d", &p[i].btime);
        printf("Enter the arrival time of process %d: ", p[i].pid);
        scanf("%d", &p[i].arrival_time);
    }

    // Sort the processes based on their arrival time using Bubble Sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                // Swap the processes
                struct sjf temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    p[0].wtime = 0;
    p[0].ttime = p[0].btime;
    tottime += p[0].ttime;

    for (int i = 1; i < n; i++) {
        p[i].wtime = p[i - 1].wtime + p[i - 1].btime;
        p[i].ttime = p[i].btime + p[i].wtime;
        tottime += p[i].ttime;
        totwtime += p[i].wtime;
    }

    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].btime, p[i].wtime, p[i].ttime);
    }

    printf("\nTotal waiting time: %d\n", totwtime);
    printf("Average waiting time: %.2f\n", (float)totwtime / n);
    printf("Total turnaround time: %d\n", tottime);
    printf("Average turnaround time: %.2f\n", (float)tottime / n);
}

