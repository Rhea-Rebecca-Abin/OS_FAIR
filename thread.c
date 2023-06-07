//Program to create a thread in linux
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *thread_function(void *arg);
int main(){
int i,n,j;

pthread_t athread;
pthread_create(&athread,NULL,thread_function,NULL);
pthread_join(athread,NULL);
printf("\nInside main program ");
for (int j=20;j<25;j++){
    printf("%d\n",j);
    sleep(1);}}
    
    void *thread_function(void *arg){
       printf("\nInside thread");
       for (int i=0;i<5;i++){
              printf("\n%d",i);
              sleep(2);
              }
              
            }
            
    


