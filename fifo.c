#include<stdio.h>
int p[100],f[100],m,n;
struct fifo{
	int free;
	int cou;	
}lf[20];

void display(int a)
{
	int i;
	printf("%d\t",p[a]);
	for(i=0;i<m;i++)
	{
		printf("%d\t",f[i]);
	}
	printf("\n");	
}
 void main()
 {
 	int j =0,flag =0, c= 0, x=0,i,k,xp;
 	printf("Enter the number of pages: ");
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		printf("Enter the page %d: ",i+1);
 		scanf("%d",&p[i]);
 	}
 	printf("Enter the number of FRAMES: ");
 	scanf("%d",&m);
 	
 	for(i=0;i<n;i++)
 	{
 		f[i]=-1;
 		lf[i].cou=0;
 	}
 	
 	printf("Pages\tFrames\n");
 	
 	for(i=0;i<n;i++)
 	{
 		flag=0;
 		for(k=0;k<m;k++)
 		{
 			if(p[i]==f[k])
 			{
 				lf[k].free++;
 				flag=1;
 				break;
 			}
 		}
 		if(k==m)
		{
			if(x<m)
			{
				f[x]=p[i];
				lf[x].free++;
				x++;
			}
		}
		else
		{
			xp=0;
			for(k=1;k<m;k++)
			{
				if(lf[k].free<lf[xp].free)
				{
					xp= k;
				}
				else if(lf[k].free==lf[xp].free && lf[k].cou==lf[xp].cou)
				{
					xp= k;
				}
				f[xp]=p[i];
				lf[xp].free = 1;
				lf[xp].cou = c++;
			}
			c++;
		}
		display(i);
 	}
 	printf("No of page faults :%d",c);
 	
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
