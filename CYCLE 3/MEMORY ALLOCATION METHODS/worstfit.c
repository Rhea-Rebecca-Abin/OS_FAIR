#include <stdio.h>
#include<stdlib.h>
#define MAX 20
void implimentworstFit(int blockSize[], int blocks, int processSize[], int processes)
{
   
    int allocation[processes];
    
    for(int i = 0; i < processes; i++){
        allocation[i] = -1;
    }
 
   
    for (int i=0; i < processes; i++)
    {
        
        int indexPlaced = -1;
        for (int j=0; j < blocks; j++) 
        { 
            if (blockSize[j] >= processSize[i])
            {
              
                if (indexPlaced == -1)
                    indexPlaced = j;
                    
              
                else if (blockSize[indexPlaced] < blockSize[j])
                    indexPlaced = j;
            }
        }
 
    
        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
 
            blockSize[indexPlaced] -= processSize[i];
        }
    }
 
    printf("\nProcess No.\tProcess Size\t\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
 
// Driver code
int main()
{   
 int i;
    int blockSize[MAX];
    int processSize[MAX],blocks,processes;
    printf("Enter no of processes");
    scanf("%d",&processes);
    printf("Enter no of  blocks");
    scanf("%d",&blocks);
    printf("Enter process sizes:");
    for (i=0;i<processes;i++){
            scanf("%d",&processSize[i]);}
    printf("Enter block sizes:");
    for (i=0;i<blocks;i++){
            scanf("%d",&blockSize[i]);}
 
    implimentworstFit(blockSize, blocks, processSize, processes);
 
    return 0 ;
}
/*OUTPUT
Enter no of processes4
Enter no of  blocks4
Enter process sizes:100
35
24
99
Enter block sizes:34
90
100
60

Process No.	Process Size		Block no.
1 			 100 			3
2 			 35 			2
3 			 24 			4
4 			 99 			Not Allocated
*/
