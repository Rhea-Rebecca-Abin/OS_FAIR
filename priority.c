//Pre-emptive Priority Scheduling
#include<stdio.h>
#include<stdlib.h>
#define MAX 30
struct priority{
int at;
int bt;
int tt;
int ct;
int wt;
int pt;
};

struct priority p[MAX];

void main(){

  int n,i,t,count=0,short_p;
  float TOT_WT=0,TOT_TT=0,AVG_WT,AVG_TT;
  printf("Enter no of processes required:");
  scanf("%d",&n);
  int temp[n];
  printf("Enter arrival , burst time and priority");
  for (i=0;i<n;i++){
         scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pt);
         temp[i]=p[i].bt;
         }
  
   p[MAX-1].pt=100000;
   for (t=0;count!=n;t++){
           short_p=MAX-1;
           for(int i=0;i<n;i++){
                  if(p[short_p].pt>p[i].pt && p[i].at<=t && p[i].bt>0){
                              short_p=i;
                              }}
           p[short_p].bt--;
           if(p[short_p].bt==0){
                      
                      count++;
                      p[short_p].ct=t+1;
                      p[short_p].tt=t+1-p[short_p].at;
                      p[short_p].wt=t+1-p[short_p].at-temp[short_p];
                      TOT_WT+=p[short_p].wt;
                      TOT_TT+=p[short_p].tt;
                      }
           }
                   
     printf("\nPID\tArrival time\t\tBURST\t\tPriority\t\tWAITING TIME\tCOMPLETION TIME\t\tTURNAROUNF TIME\n");
                       
    for(int i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,p[i].at,temp[i],p[i]pt.p[i].wt,p[i].ct,p[i].tt);
                  }
           
  printf("Average wait time:%f",TOT_WT/n);
  printf("Avergae turntime :%f",TOT_TT/n);
  }
           
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
