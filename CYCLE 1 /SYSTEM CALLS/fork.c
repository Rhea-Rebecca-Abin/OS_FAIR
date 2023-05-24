// fork system call
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
 int pid,pid1,pid2;
 pid=fork();
 if (pid == -1){
     printf("Error\n");
     exit(1);
   }
if (pid!=0){
     pid1=getpid();
     printf("\nthe parent process Id is %d\n",pid1);
 }
else{
   pid2=getpid();
    printf("\nthe child process Id is %d\n",pid2);}
return 0;}

/* OUTPUT


the parent process Id is 2332

the child process Id is 2333
*/
