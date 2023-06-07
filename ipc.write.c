#include<stdio.h>
#include<stdlib.h>

#include<sys/shm.h>
#include<unistd.h>
#include<string.h>

int main(){

void *shared_memory;
char buff[100];
int shmid;
shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
printf("\nKey of shared memory system is %d\n:",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("\nProcess attached at %p\t\n",shared_memory);
printf("\nEnter data to be written:\n");
read(0,buff,100);
strcpy(shared_memory,buff);
printf("\nWritten these things :%s\n",(char*)shared_memory);}

