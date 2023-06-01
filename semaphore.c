#include <stdio.h>

int mutex=1,empty=5,full=0,x=0;
int buffer[5];

int down(int s){

      s= s-1;  
      return s;

}

int up(int s){
        s=s+1;
        return s;
}


int producer(){
      
      empty = down(empty);
      mutex = down(mutex);
      x++;
      printf("The producer produced %d\n",x);
      mutex = up(mutex);
      full = up(full);
        
}
int consumer(){
        
        full = down(full);
        mutex = down(mutex);
        printf("Consumer consumed %d\n",x);
        x--;
        mutex = up(mutex);
        empty = up(empty);
}
int main()
{
        int c;
        while (c!=3){
                printf("1.Producer\n2.Consumer\n3.Exit\nEnter your option  :");
                scanf("%d",&c);
                printf("\n");
                switch(c){
                        
                        case 1: if(mutex ==1 && empty !=0){
                                
                                producer();
                                }
                                else{
                                printf("Buffer is full\n");
                                }
                                break;
                                
                        case 2: if(mutex ==1 && full !=0){
                                
                                consumer();
                                }
                                else{
                                printf("Buffer is empty\n");
                                }
                                
                }
                
        }  
}
