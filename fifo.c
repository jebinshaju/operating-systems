#include<stdio.h>
int main(){
        int i,j,k,flag=0;
        int f[20],p[20],f0,p0,count = 0,x=0;
        
        printf("Enter the number frames: ");
        scanf("%d",&f0);
        printf("Enter the number pages: ");
        scanf("%d",&p0);
        
        printf("Enter the page refernces: ");
        for(i=0;i<p0;i++){
                
                scanf("%d",&p[i]);
        }
        for(i=0;i<f0;i++){
                
                f[i]=-1;
        }
        for(i=0;i<p0;i++){
                
                flag =0;
                for(k=0;k<f0;k++){
                        if(p[i]==f[k]){
                                flag = 1;
                                break;
                        }
                }
                if(flag == 0){
                        f[x]=p[i];
                        x=(x+1)%f0;
                        count = count+1;
                }
                printf("%d\t",p[i]);
                for(j=0;j<f0;j++){
                     printf("%d",f[j]);   
                }
                if(p[i]==f[k]){
                        printf("\tHIT");
                }
                else{
                        printf("\tMISS");
                }
                printf("\n");
                 
        }
        printf("Page fault %d ",count);         
}
