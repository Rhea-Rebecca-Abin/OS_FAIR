#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>


void trav(const char*path){
       DIR *dir=opendir(path);
       if(dir==NULL){
              fprintf("Error opening directory: %s\t",path);
              return;}
              
       struct dirent* entry;
       while((entry=readdir(path))!=NULL){
           
            if(entry->d_type== DT_DIR)
            
             if(strcmp(entry->d_name,..)==0 || strcmp(entry->d_name,..)==0){
                     continue;}
             














int main(int argc, char *argv[]){
              if(argc!=2){
                  printf("\nUsage ./a.out <dir path>");exit(1);
                  
                  }
              printf("PArent iD %d, traversing directory %s",getpid,argv[1]); 
              trav(argv[1]);
              return 0;}
              
