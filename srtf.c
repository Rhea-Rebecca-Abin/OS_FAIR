#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct sjf
 { 
  int pid;
  int btime;
  int temp_btime;
  int atime;
  int ctime;
  int wtime;
  int ttime;
  };
int tottime,totwtime=0;

void main(){  
int n;
int t;
printf("Enter no of processes:");
scanf("%d",&n);
int sum_b=0;
struct sjf p[MAX];

for(int i=0;i<n;i++){
     p[i].pid=i+1;
     printf("Enter burst time of process, arrival%d:",p[i].pid);
     scanf("%d%d",&p[i].btime,&p[i].atime);
     p[i].temp_btime=p[i].btime;
     //sum_b+=p[i].btime;
     }

p[MAX-1].btime=999999;
int count=0;
  for( t=0;count!=n;t++){
         int shortest_job=MAX-1;
         for (int i=0;i<n;i++){
                     if(p[i].atime<=t && p[i].btime<p[shortest_job].btime && p[i].btime>0){
                                       shortest_job=i;}}
                                       
         
         p[shortest_job].btime--;
         if(p[shortest_job].btime==0){
         p[shortest_job].ctime=t+1;
         p[shortest_job].ttime=t+1-p[shortest_job].atime;
         p[shortest_job].wtime=p[shortest_job].ttime-p[shortest_job].temp_btime;
       
        
         tottime+=p[shortest_job].ttime;
         totwtime+=p[shortest_job].wtime;
         count++;     }
         }
       
                
              
printf("\nPID\tArrival time\tBurst time\tWaiting time\tTurnaround Time");
for (int i=0;i<n;i++){
      printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].atime,p[i].temp_btime,p[i].wtime,p[i].ttime);
      
      }

printf("\nTotal waiting time %d",totwtime);
printf("\nAverage waiting time %f",(float)totwtime/n);
printf("\nTotal turnaround time %d",tottime);
printf("\nAverage turnaround time %f\n",(float)tottime/n);

}


