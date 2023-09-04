#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unisted.h>

sem_t room;
sem_t chopstick[5];
void *philosopher(void *);
void eat(int);



void eat(int phil){
    printf("Philosopher %d is eating ",phil);
    }
int main(){
  int i, a[5];
  pthread_t tid[5];
  
