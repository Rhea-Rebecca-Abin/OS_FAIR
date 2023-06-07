#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(int argc,char* argv[4]){
    struct dirent *entry;
    DIR *dir;
    char buff[10000];
    FILE *source_fp,*dest_fp;
    if(argc!=4){
         printf("Incorrect usage ./a.out <source><destination><dir path>");
         printf("\n");
         exit(1);}
    source_fp=fopen(argv[1],"rb");
    if(source_fp ==NULL){
        printf("\nError opening source file :");
        }
    dest_fp=fopen(argv[2],"wb");
    if(dest_fp==NULL){
          printf("\nError opeing destination file:");
          }
   size_t bytes_read,bytes_written;
   while((bytes_read=fread(buff,1,sizeof(buff),source_fp))>0){
                  
                  bytes_written=fwrite(buff,1,bytes_read,dest_fp);
                  if(bytes_read!=bytes_written)
                        printf("\nError");}
  fclose(source_fp);
  fclose(dest_fp);                      
  printf("\nSuccesfully copied ");
  dir=opendir(argv[3]);
  if(dir==NULL){
       printf("Error opening directory ");}
  else {
  
        while((entry=readdir(dir))!=NULL){
             printf("%s\t",entry->d_name);
             }}
  
  
  closedir(dir);
  
  return 0;}             
                  
                  
   
