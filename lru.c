#include<stdio.h>
void main()
{
        int fn, pn, f[50],p[50],t[50],pos,flag1,flag2,page_fault = 0,x=0,i,j,k;
        
        printf("Enter the number of frames: ");
        scanf("%d",&fn);
        printf("Enter the number of pages: ");
        scanf("%d",&pn);
        
        printf("Enter the page refernce: ");
        for(i=0;i<pn;i++)
        {
                scanf("%d",&p[i]);
        }
        
        for(j=0;j<fn;j++){
                f[j]=-1;
                
        }
        
        printf("\nPage Reference \tFrames");
        for(i=0;i<pn;i++){
                flag1 = flag2 =0;
                for(j=0;j<fn;j++){
                        if(p[i]==f[j])
                        {
                                printf("hit");
                                t[j]=i;
                                flag1 = flag2 =1;
                        }
                }
        }
}
