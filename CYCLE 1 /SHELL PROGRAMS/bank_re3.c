#include <stdio.h>
#include <stdlib.h>
int m,n;
void banker(int n, int m, int **need, int *avail, int **alloc, int *f, int *ans) {
int i,j,k,y,ind=0;
    // Function implementation remains the same...
    // (Your existing implementation of the banker function)
    for(k=0;k<n;k++){
    for(i=0;i<n;i++){
        if(f[i]==0){
        int flag=0;
        
        for(j=0;j<m;j++){
        
            if(need[i][j]>avail[j]){
                   flag=1;
                   break;}}
        if(flag==0){
                 ans[ind++]=i;
                 for(y=0;y<m;y++){
                        avail[y]+=alloc[i][y];
                        }        
                 f[i]=1;}
                 
             }}}
printf("\nbanker's done");int x=1;
 for (i=0;i<n;i++){
       if(f[i]==0){
           x=0;
           printf("\n Not safe");
           break;}}

if (x==1){
    printf("\nFollowing is the safe sequence");
    for(i=0;i<n-1;i++){
       printf("P%d->",ans[i]);
       }
     printf("P%d",ans[n-1]);         
    }
}

int main() {
    int c, p;;
    printf("Enter no of processes:");
    scanf("%d", &n);
    printf("Enter no of resources:");
    scanf("%d", &m);
    int temp[m],req[m];;
    int i, j, k, y, *avail, **max, **alloc, **need, *f, *ans;

    // Allocate memory for arrays
    avail = (int *)malloc(m * sizeof(int));
    f = (int *)malloc(n * sizeof(int));
    ans = (int *)malloc(n * sizeof(int));

    max = (int **)malloc(n * sizeof(int *));
    alloc = (int **)malloc(n * sizeof(int *));
    need = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        max[i] = (int *)malloc(m * sizeof(int));
        alloc[i] = (int *)malloc(m * sizeof(int));
        need[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter max matrix");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter allocation matrix");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter available matrix");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
        temp[i]=avail[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    banker(n, m, need, avail, alloc, f, ans);

    while (1) {
        printf("\nAdditional requests ? 1-yes, 0-no");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("\nEnter process no requesting additional resource 0 to %d", n - 1);
                scanf("%d", &p);

                for (i = 0; i < m; i++) {
                    printf("Enter no of resource type %d\t:", i + 1);
                    scanf("%d", &req[i]);
                }

                // Resource request algorithm
                for (j = 0; j < m; j++) {
                    temp[j] -= req[j];
                    alloc[p][j] += req[j];
                    need[p][j] -= req[j];
                }

                printf("\nNeed matrix");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("%d\t", need[i][j]);
                    }
                    printf("\n");
                }

                printf("\nAllocation matrix");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("%d\t", alloc[i][j]);
                    }
                    printf("\n");
                }

                printf("\nAvailable matrix");
                for (i = 0; i < m; i++) {
                    printf("%d\t", temp[i]);
                }
                printf("\n");

                // Check safety again
                for (i = 0; i < n; i++) {
                    ans[i] = -1;
                    f[i] = 0;
                }

                banker(n, m, need, temp, alloc, f, ans);
                break;

            case 0:
                exit(0);
        }
    }

    // Free dynamically allocated memory
    free(avail);
    free(f);
    free(ans);

    for (i = 0; i < n; i++) {
        free(max[i]);
        free(alloc[i]);
        free(need[i]);
    }
    free(max);
    free(alloc);
    free(need);

    return 0;
}

