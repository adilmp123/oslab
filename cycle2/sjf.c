#include <stdio.h>
typedef struct
{
    int id,bt,wt,tat,ct,at;
}pcb;
void sortWithBurstTime(pcb pr[],int n)
{
    int i,j;
    pcb temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(pr[j].bt >pr[j+1].bt)
            {
                temp=pr[j];
                pr[j]= pr[j+1];
                pr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n,i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    pcb pr[n];
    int bt[n],at[n],wt[n],tat[n],ct[n];
    printf("Enter id the burst times of n processes: \n");
    int sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&pr[i].id);
        scanf("%d",&pr[i].bt);
        pr[i].at=0;
    }
    sortWithBurstTime(pr,n);
    for(i=0;i<n;i++)
    {
        sum+=pr[i].bt; 
        pr[i].ct=sum;
    }
    int totalTAT=0,totalWT=0;
    for(i=0;i<n;i++)
    {
        pr[i].tat = pr[i].ct-0;
        totalTAT+=pr[i].tat;
    }
    float avgTAT = (float)totalTAT/n;
    for(i=0;i<n;i++)
    {
        pr[i].wt = pr[i].tat-pr[i].bt;
        totalWT+=pr[i].wt;
    }
    float avgWT = (float)totalWT/n;
    printf("\nPNo\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pr[i].id,pr[i].at,pr[i].bt,pr[i].ct,pr[i].tat,pr[i].wt);
    }
    printf("\n");
    printf("Average Waiting time = %f\n",avgWT);
    printf("Average Turn Around time = %f\n",avgTAT);
}
