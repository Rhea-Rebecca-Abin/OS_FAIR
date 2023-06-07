#include<stdio.h>
#include<stdlib.h>

void bestfit(int block[],int m,int process[],int n){
     int i,j;
     int allocation[n];
     for (i=0;i<n;i++){
           allocation[i]=-1;}
           
     for(i=0;i<n;i++){
     
        int index=-1;
        for(j=0;j<m;j++){
             
             if(block[j]>=process[i]){
                    
                   if(index==-1){
                        index=j;}
                   else 
                        if (block[j]<block[index]){
                             index=j;
                             }}}
                             
       if(index!=-1){
           allocation[i]=index;
           block[index]=block[index]-process[i];
           }
           }
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                      
    printf("\nProcess no\tProcess Size\tBlock no\n");
    for(i=0;i<n;i++){
    printf("\n%i\t\t\t%i\t\t\t",i+1,process[i]);
    
    if(allocation[i]!=-1){
         printf("%i",allocation[i]+1);
         }
    else 
         printf("Not Allocated");
    printf("\n");
    }
        }      

int main(){
     int m,n;
    
     printf("\nEnter nof processes:");
     scanf("%d",&n);
     printf("\nENter no of blocks:");
     scanf("%d",&m);
     int process[n],block[m];
     
     for (int i=0;i<n;i++){
           printf("\nEnter process size :");
           scanf("%d",&process[i]);}
           
     for(int j=0;j<m;j++){
           printf("ENter block size :");
           scanf("%d",&block[j]);}
           
           
     bestfit(block,m,process,n);
     return 0;
     }
     
           
     
     
     
     
     
     
     
     
     
