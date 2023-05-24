#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024

void usage(){
    printf("Usage :./a.out filename word \n");
    }
 int main(int argc,char *argv[]){
        if(argc!=3){
              usage();
              exit(1);}

 FILE *fp;
 char fline[MAX];
 char *newline;
 int count=0;
 int occurrences=0;
 fp=fopen(argv[1],"r");
 if(fp==NULL){
       printf("\nCould not open file %s\n",argv[1]);
       exit(1);}
       
 while(fgets(fline,MAX,fp)!=NULL){
        count++;
        if(newline=strchr(fline,'\n'))
               *newline='\0';
               if(strstr(fline,argv[2])!=NULL){
                      printf("%s:%d %s\n",argv[1],count,fline);
                      occurrences++;
                      }}}
                      
/*OUTPUT

hope.txt:1 Hope is the thing with feathers
hope.txt:6 Hope is the anchor for the heart
hope.txt:11 Hope is the star that guides our way
*/
