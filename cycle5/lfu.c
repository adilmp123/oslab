#include <stdio.h>
#define MAX 100
int front = -1, rear = -1;
int queue[MAX];
int position(int item)
{
    for (int i = front; i < rear; i++)
    {
        if (queue[i] == item)
        {
            return i;
        }
    }
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void enqueue(int item)
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
        queue[rear++] = item;
    }
    else
    {
        queue[rear++] = item;
    }
}
int dequeue()
{
    return queue[front++];
}
void removeItem(int item)
{
    for(int i=0;i<rear;i++)
    {
        if(queue[i]==item)
        {
            for(int j=i;j>front;j--)
            {
                swap(queue+j,queue+j-1);
            }
        }
    }
    dequeue();
}
int main()
{
    int f = 0, p = 0, smallest;
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    printf("Enter the number of pages: ");
    scanf("%d", &p);

    int frames[f], reference_string[p], frequency[f];

    printf("Enter the reference string: ");
    for (int i = 0; i < p; i++)
        scanf("%d", &reference_string[i]);

    for (int i = 0; i < f; i++)
    {
        frames[i] = -1;
        frequency[i] = 0;
    }

    int hit = 0, miss = 0;

    for (int i = 0; i < p; i++)
    {
        int minus=1;
        int page = reference_string[i];
        int flag = 0;

        for (int k = 0; k < f; k++)
        {
            if (frames[k] == page)
            {
                flag = 1;
                hit++;
                frequency[k]++;
                break;
            }
        }
        if (flag == 0)
        {
            for (int ind = 0; ind < f; ind++)
            {
                if (frames[ind] == -1)
                {
                    enqueue(page);
                    frames[ind] = page;
                    frequency[ind] = 1;
                    minus=0;
                    break;
                }
            }
        }

        if (flag == 0 && minus)
        {
            int min_frequency = frequency[0];
            int min_frequency_index = 0;

            for (int k = 1; k < f; k++)
            {
                if (frequency[k] < min_frequency)
                {
                    min_frequency = frequency[k];
                    min_frequency_index = k;
                }
            }
            smallest = min_frequency_index;
            for (int k = 0; k < f; k++)
            {
                if (frequency[k] == min_frequency && position(frames[k]) < position(frames[smallest]))
                {
                    smallest = k;
                }
            }
            min_frequency_index = smallest;
            enqueue(page);
            if(i>2)
            {
                removeItem(frames[min_frequency_index]);
            }
            frames[min_frequency_index] = page;
            frequency[min_frequency_index] = 1;
            miss++;
        }

        printf("Page frame: ");
        for (int k = 0; k < f; k++)
            printf("%d ", frames[k]);
        printf("\n");   
    }

    printf("Number of hits: %d\n", hit);
    printf("Number of misses: %d\n", miss);
    printf("Hit ratio: %f\n", (float)hit / (float)p);
    printf("Miss ratio: %f\n", (float)miss / (float)p);

    return 0;
}
