//cp and ls 
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(int argc,char* argv[]){
      DIR *dir;
      struct dirent *entry;
      FILE *source_fp,*dest_fp;
      char buffer[4096];
      size_t bytes_read,bytes_written;
      if (argc!=4){
         printf("Usage %s<source_file><dest_file><dir_path>\n",argv[0]);
         exit(1);}
      
      source_fp=fopen(argv[1],"rb");
      if(source_fp==NULL){
              printf("Error opening source file %s\n",argv[1]);
              exit(1);}
      dest_fp=fopen(argv[2],"wb");
      if(dest_fp==NULL){
              printf("Error opening destination file %s\n",argv[2]);
              exit(1);}
              
      
      while((bytes_read=fread(buffer,1,sizeof(buffer),source_fp))>0){
                  
                  bytes_written=fwrite(buffer,1,bytes_read,dest_fp);
                  if(bytes_written!=bytes_read){
                        printf("Error writing to destination file :%s\n",argv[2]);
                        fclose(source_fp);
                        fclose(dest_fp);
                        exit(1);
                                               }}
      printf("\nCopied contents from source file to the destination file\n");
      
      fclose(source_fp);
      fclose(dest_fp);
      printf("\nDisplaying the files in the directory \n");
      dir=opendir(argv[3]);
      if(dir==NULL){
            printf("\nError opening directory %s",argv[3]);
            }
      while((entry=readdir(dir))!=NULL){
                            
                printf("%s\n",entry->d_name);
                }
     closedir(dir);
     return 0;
     }
                      
/*OUTPUT
Copied contents from source file to the destination file

Displaying the files in the directory 
fork.c
grep2.c
a.out
..
grep.c
dest.txt
source.txt
cp.c
grep2.1c
.
fork2.c

SOURCE FILE
Being positive is a mindset and attitude 
that focuses on the brighter side of life,
even in challenging or difficult situations. 

DESTINATION FILE
Being positive is a mindset and attitude 
that focuses on the brighter side of life,
even in challenging or difficult situations. 


*/                      
                      
                      
                      
                      
                      
                      
                             
   
