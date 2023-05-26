
#include<stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n)
{
	int i, j;
	
	int allocation[n];

	
	for(i = 0; i < n; i++)
	{
		allocation[i] = -1;
	}

	
	for (i = 0; i < n; i++)	 
	{
		for (j = 0; j < m; j++)	 
		{
			if (blockSize[j] >= processSize[i])
			{
				
				allocation[i] = j;
				blockSize[j] -= processSize[i];
             			break; 
			}
		}
	}

	printf("\nProcess No.\tProcess Size\t\t\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %i\t\t\t", i+1);
		printf("%i\t\t\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}

// Driver code
int main()
{       
 int i;
	int m; //number of blocks in the memory
	int n; //number of processes in the input queue
	int blockSize[10];
	int processSize[10];
        printf("Enter no. of blocks: ");
	scanf("%d", &m);
	printf("\nEnter size of each block: ");
	for(i = 0; i < m; i++)
		scanf("%d", &blockSize[i]);
	printf("\nEnter no. of processes: ");
	scanf("%d", &n);
	printf("\nEnter size of each process: ");
	for(i = 0; i < n; i++)
		scanf("%d", &processSize[i]);
	

	firstFit(blockSize, m, processSize, n);

	return 0 ;
}
/* OUTPUT
Enter no. of blocks: 5

Enter size of each block: 100
500
200
300
600

Enter no. of processes: 4  

Enter size of each process: 212
417
112
426

Process No.	Process Size			Block no.
 1			212				2
 2			417				5
 3			112				2
 4			426				Not Allocated
*/
