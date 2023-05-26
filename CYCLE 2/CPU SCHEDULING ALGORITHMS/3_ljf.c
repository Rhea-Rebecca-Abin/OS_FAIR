#include<stdio.h>
#include<stdlib.h>

struct ljf
 { 
  int pid;
  int btime;
  int wtime;
  int ttime;
  };
int tottime,totwtime=0;
void main(){  
int n;
int t;
printf("Enter no of processes:");
scanf("%d",&n);

struct ljf p[n];

for(int i=0;i<n;i++){
     p[i].pid=i+1;
     printf("Enter burst time of process %d:      ",p[i].pid);
     scanf("%d",&p[i].btime);}


for (int i=0;i<n;i++){
    for (int j=0;j<n-i-1;j++){
            
            if(p[j].btime<p[j+1].btime){
                   t=p[j].btime;
                   p[j].btime=p[j+1].btime;
                   p[j+1].btime=t;}
                   }}           
p[0].wtime=0;
p[0].ttime=p[0].btime;
tottime+=p[0].ttime;
for(int i=1;i<n;i++){
     p[i].wtime=p[i-1].wtime+p[i-1].btime;
     p[i].ttime=p[i].btime+p[i].wtime;
     tottime+=p[i].ttime;
     totwtime+=p[i].wtime;
                
                }
              
printf("PID\tBUrst time\tWaiting time\tTurnaround Time");
for (int i=0;i<n;i++){
      printf("\n%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].btime,p[i].wtime,p[i].ttime);
      
      }

printf("\nTotal waiting time %d",totwtime);
printf("\nAverage waiting time %f",(float)totwtime/n);
printf("\nTotal turnaround time %d",tottime);
printf("\nAverage turnaround time %f\n",(float)tottime/n);

}

/* OUTPUT

Enter no of processes:4
Enter burst time of process 1:      3
Enter burst time of process 2:      5
Enter burst time of process 3:      5
Enter burst time of process 4:      10
PID	BUrst time	Waiting time	Turnaround Time
1		10		0		10

2		5		10		15

3		5		15		20

4		3		20		23

Total waiting time 45
Average waiting time 11.250000
Total turnaround time 68
Average turnaround time 17.000000
*/




