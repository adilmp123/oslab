#include <stdio.h>
#include <stdlib.h>
int mutex = -1;
int full =0;
int empty=5;
int x=0;
void producer()
{
    mutex--;
    full++;
    --empty;
    x++;
    printf("producer produces item %d",x);
    mutex++;
}
void consumer()
{
    mutex--;
    full--;
    empty++;
    printf("consumer consumes item %d",x);
    x--;
    mutex++;
}
int main()
{
    int n;
    printf("\nProducer consumer problem");
    printf("\n1. producer");
    printf("\2. consumer");\
    printf("\n Enter the choice: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            if(mutex==1 && empty!=0)
            {
                producer();
            }
            else
            {
                printf("Buffer is full");
            }\
            break;
        case 2:
            if(mutex==1 && full!=0)
            {
                consumer();
            }
            else
            {
                printf("Buffer is empty");
            }
            break;
        case 3:exit(0);
        default:break;
    }
}

