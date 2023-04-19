#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int empty = 5,full=0;
int count=0;

int wait(int S)
{
    while(S<=0);
    return --S;
}

int signal(int S)
{
    return ++S;
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    printf("produced item %d",++count);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("produced item %d",count--);
    mutex = signal(mutex);
}

int main()
{
    int n;
    while(1)
    {
        printf("\n1. Producer");
        printf("\n2. Consumer");
        printf("\n3. Exit");
        printf("\nEnter the choice: ");
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
                }
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
            default:
                printf("Enter valid choice");
                break;
        }
        printf("\n\n");
    }
}
