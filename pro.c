#include<stdio.h>
#include<stdlib.h>

int mutex=1, full=0,empty=4;
int x=0;


int wait(int);
int signal(int);
void producer();
void consumer();

int wait(int s){
    return(--s);}
    
int signal(int s){
    return (++s);}

void producer(){
      mutex=wait(mutex);
      x++;
      empty=wait(empty);
      full=signal(full);
      printf("Producer produces item %d\t",x);
      mutex=signal(mutex);
      }
      
void consumer(){
     mutex=wait(mutex);
    
     full=wait(full);
     empty=signal(empty);
     printf("Consumer consumes item %d\t",x);
     x--;
     mutex=signal(mutex);
     }
     
void main(){
   int n;
   printf("\n1.Producer\n2.Consumer\n3.Exit");
   while(1){
         printf("ENter choice:");
         scanf("%d",&n);
         switch(n){
            case 1:{
                if(mutex==1 && empty!=0)
                   producer();
                else
                    printf("\nBuffer is full");
                break;}
             case 2:
                 {if(mutex==1 && full!=0)
                   consumer();
                   
                  else 
                       printf("\nBuffer is empty");
                       
                   break;}
             case 3:
                 {exit(1);
                 break;}
                 }}
          }
                        
     
     
  
