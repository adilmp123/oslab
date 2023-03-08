#include <stdio.h>
int main()
{
    int n,i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int bt[n],at[n],wt[n],tat[n],ct[n];
    printf("Enter the arrival times of n processes: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",at+i);
    }
    printf("Enter the burst times of n processes: ");
    int sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",bt+i);
        sum+=bt[i];
        ct[i]=sum;
    }
    int totalTAT=0,totalWT=0;
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        totalTAT+=tat[i];
    }
    float avgTAT = (float)totalTAT/n;
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        totalWT+=wt[i];
    }
    float avgWT = (float)totalWT/n;
    printf("\nPNo\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\n");
    printf("Average Waiting time = %f\n",avgWT);
    printf("Average Turn Around time = %f\n",avgTAT);

}
