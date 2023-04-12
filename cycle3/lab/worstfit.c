#include <stdio.h>
void worstfit(int block[], int m, int process[], int n)
{
    int bestBlock;
    int allocation[n];
    for(int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        bestBlock=-1;
        for(int j=0;j<m;j++)
        {
            if(block[j]>=process[i])
            {
                if(bestBlock==-1)
                {
                    bestBlock=j;
                }
                else if(block[j]>block[bestBlock])
                {
                    bestBlock=j;
                }
            }
        }
        if(bestBlock!=-1)
        {
            allocation[i]=bestBlock;
            block[bestBlock]-=process[i];
        }
    }
    printf("\nPNo\tPSize\tBlockNo");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t%d\t",i+1,process[i]);
        if(allocation[i]!=-1)
        {
            printf("%d",allocation[i]+1);
        }
        else
        {
            printf("Not Allocated");
        }
    }
    printf("\n");
}
int main()
{
    // int m,n;
    // printf("Enter the no of blocks: ");
    // scanf("%d",&m);
    // int block[m];
    // printf("Enter size of %d blocks: ");
    // for(int i=0;i<m;i++)
    // {
    //     scanf("%d",block+i);
    // }
    // printf("Enter the no of processes: ");
    // scanf("%d",&n);
    // int process[n];
    // printf("Enter size of %d processes: ");
    // for(int i=0;i<n;i++)
    // {
    //     scanf("%d",process+i);
    // }

    int block[]={100,500,200,300,600};
    int process[]={212, 417, 112, 426};
    int m=5,n=4;
    worstfit(block,m,process,n);

}