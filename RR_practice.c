#include <stdio.h>
int q[100],front=-1,rear=-1;
struct process
{int id,at,tt,bt,wt,rt,ct,status;
}p[20];


void enqueue(int j){
    if(front ==-1 && rear==-1){
            queue[rear]=j;
            }
            }
int dequeue(){
    if(front ==-1){
       return -1;
       }
    else if(front ==-1 && rear ==-1){
           return -1)}
    else {
    int item =queue[front];
    return item;}}

   
           





















void main()
{ int n,quantum,completed=0,qExpire=0, status=0,time=0,ditem=-1;
 float avwt=0,avtt=0;
 printf("Enter the number of processes : ");
 scanf("%d",&n);
 printf("\nEnter the AT and BT :\n");
 for(i=0;i<n;i++) //Input process details
 {
 p[i].id = i+1; p[i].status = 0;
 scanf("%d",&p[i].at);
 scanf("%d",&p[i].bt);
 p[i].rt = p[i].bt;
 }
 printf("\nEnter time quantum : ");
 scanf("%d",&quantum);
 
 while(time==p[0].at){
         time++;}
 enqueue(0);
 p[0].status=1;
 
 while(completed<n){
       
       //1.Check dequeued item ==-1
       if(ditem==-1){
              ditem=dequeue();}
              
       time++;
       
       //2.Enqueue arrived processes    
       for(int i=0;i<n;i++){
            
            if(p[i].at<=time && p[i].status ==0){
                     enqueue(i);
                     p[i].status=1;}}
                     
       //3.Process the dequeued items
       if(ditem!=-1){
             
             //not expire and rt>0
             if(qExpire!=quantum && p[i].rt>0){
                      p[i].rt--;
                      qExpire++;}
             //rt=0
             else if(p[ditem].rt ==0){
                    p[ditem].ct==time;
                    p[ditem].tt = p[ditem].ct - p[ditem].at;
                    p[ditem].wt = p[ditem].tt - p[ditem].bt
                    completed++;
                    avwt+=p[ditem].wt;
                    avtt+=p[ditem].tt;
                    completed++;
                    ditem=0;
                    qExpire=0;
                    }
             
             
             //qexpired
             else if(qExpire ==quantum){
                   enqueue(ditem);
                   ditem=0;
                   qExpire=0;}
                   }      
                    }}
                     
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 printf("\nPRD\tARRTIME\tBURST\tCOMPLETION\tWAITING\tTURNAROUND\n\n");
for(i=0;i<n;i++)
{printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tt);
 }
 printf("\n\nAverage Waiting Time : %f",(avwt/n));
 printf("\nAverage Turn Around Time : %f\n",(avtt/n));
}

