#include <stdio.h>

int main() {
    int frames, pages;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("Enter the number of elements in the incoming stream: ");
    scanf("%d", &pages);

    int incomingStream[pages];
    printf("Enter the incoming stream:\n");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &incomingStream[i]);
    }

    int pageFaults = 0;
    printf("\nIncoming\t\tFrame 1\t\tFrame 2\t\tFrame 3");
    int temp[frames];
    for (int m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    for (int m = 0; m < pages; m++) {
        int s = 0;
        for (int n = 0; n < frames; n++) {
            if (incomingStream[m] == temp[n]) {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;

        if ((pageFaults <= frames) && (s == 0)) {
            temp[m] = incomingStream[m];
        } else if (s == 0) {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }

        printf("\n");
        printf("%d\t\t\t", incomingStream[m]);
        for (int n = 0; n < frames; n++) {
            if (temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
/*OUTPUT
Enter the number of frames: 3
Enter the number of elements in the incoming stream: 20
Enter the incoming stream:
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

Incoming		Frame 1		Frame 2		Frame 3
7			 7			 - 			 - 			
0			 7			 0			 - 			
1			 7			 0			 1			
2			 2			 0			 1			
0			 2			 0			 1			
3			 2			 3			 1			
0			 2			 3			 0			
4			 4			 3			 0			
2			 4			 2			 0			
3			 4			 2			 3			
0			 0			 2			 3			
3			 0			 2			 3			
2			 0			 2			 3			
1			 0			 1			 3			
2			 0			 1			 2			
0			 0			 1			 2			
1			 0			 1			 2			
7			 7			 1			 2			
0			 7			 0			 2			
1			 7			 0			 1			
Total Page Faults: 15
*/
