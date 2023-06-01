#include <stdio.h>
int max[][3],alloc[][3],need[][3],avail[][3];

int main(){
        int n;
        printf("Enter the number of processes: ");
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++)
        {
                printf("Enter the maximum \n");
                scanf("%d %d %d",&max[i][0],&max[i][1],&max[i][2]);
                printf("Enter the allocation \n");
                scanf("%d %d %d",&alloc[i][0],&alloc[i][1],&alloc[i][2]);
                need[i][0]=max[i][0]-alloc[i][0];
               need[i][1]=max[i][1]-alloc[i][1];
               need[i][2]=max[i][2]-alloc[i][2];
        }
        int j;
        for(i=0;i<n;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("%d",max[i][j]);
                        printf("\n");
                        printf("%d",alloc[i][j]);
                        printf("\n");
                        printf("%d",need[i][j]);
                }
        }
}
