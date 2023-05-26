#include<stdio.h>
#include<stdlib.h>
#define MAX 100
 struct srtf{
   int pid;
   int ttime;
   int btime;
   int wtime;
   int xtime;
   int ctime;
   int atime;
   };
struct srtf p[MAX];

void main(){
   int smallest,count=0,time,n,i,j,x,total=0;
   double avg=0,tt=0,end;
   printf("ENter the no of processes:  ");
   scanf("%d",&n);
   x=n;
   printf("Enter arrival and burst time :");
   for (i=0;i<n;i++){
       p[i].pid=i+1;
       scanf("%d%d",&p[i].atime,&p[i].btime);
       p[i].xtime=p[i].btime;
       }
   
   p[MAX-1].btime=9999;
   
   for(time=0;count!=n;time++){
         smallest=MAX-1;
         for(i=0;i<n;i++){
                 
              if(p[i].atime<=time && p[i].btime < p[smallest].btime && p[i].btime>0){
                        
                        smallest=i;
                        }}
         
         p[smallest].btime--;
         if (p[smallest].btime==0){
               count++;
               end=time+1;
               
               p[smallest].ctime=end;
               p[smallest].ttime= p[smallest].ctime-p[smallest].atime;
               p[smallest].wtime=p[smallest].ttime-p[smallest].xtime;
               avg+=p[smallest].wtime;
               tt+=p[smallest].ttime;
               }}

          printf("PID\tArrival time\tBurst time\tCompletion time\tTurn around time\tWaiting time\n");
 for(i=0;i<n;i++){
 printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].atime,p[i].xtime,
       p[i].ctime,p[i].ttime,p[i].wtime);}
 
printf("\nAverage waiting time %lf\n",avg/n);
printf("\nAverage turnaround time %lf\n",tt/n);        
           
}   
   
/*OUTPUT
ENter the no of processes:  6
Enter arrival and burst time :0 8
1 4
2 2
3 1
4 3
5 2
PID	Arrival time	Burst time	Completion time	Turn around time	Waiting time

1		0		8		20		20		12

2		1		4		10		9		5

3		2		2		4		2		0

4		3		1		5		2		1

5		4		3		13		9		6

6		5		2		7		2		0

Average waiting time 4.000000

Average turnaround time 7.333333
*/
   
   
   
   
   
   
   
   
   
   
   

