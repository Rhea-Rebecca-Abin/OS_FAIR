#include<stdio.h>
#include<stdlib.h>

struct fcfs
 { 
  int pid;
  int btime;
  int wtime;
  int ttime;
  };

void main(){  
int n;
int tottime,totwtime=0;
int count=0;
printf("Enter no of processes:");
scanf("%d",&n);

struct fcfs p[n];

for(int i=0;i<n;i++){
     p[i].pid=i+1;
     printf("Enter burst time of process %d:      ",p[i].pid);
     scanf("%d",&p[i].btime);}

p[0].wtime=0;
p[0].ttime=p[0].btime;
tottime+=p[0].ttime;
for(int i=1;i<n;i++){
     p[i].wtime=p[i-1].wtime+p[i-1].btime;
     p[i].ttime=p[i].btime+p[i].wtime;
     tottime+=p[i].ttime;
     totwtime+=p[i].wtime;
                
                }
              
printf("PID\tBurst time\tWaiting time\tTurnaround Time");
for (int i=0;i<n;i++){
      printf("\n%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].btime,p[i].wtime,p[i].ttime);
      
      }

printf("\nTotal waiting time %d",totwtime);
printf("\nAverage waiting time %f",(float)totwtime/n);
printf("\nTotal turnaround time %d",tottime);
printf("\nAverage turnaround time %f",(float)tottime/n);


}

/* OUTPUT
Enter no of processes:3
Enter burst time of process 1:      5
Enter burst time of process 2:      8
Enter burst time of process 3:      12
PID	Burst time	Waiting time	Turnaround Time
1		5		0		5

2		8		5		13

3		12		13		25

Total waiting time 18
Average waiting time 6.000000
Total turnaround time 43
Average turnaround time 14.333333
*/



