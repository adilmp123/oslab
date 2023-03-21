#include <stdio.h>
typedef struct 
{
    int id,at,bt,ct,tat,wt,rt;
}process;
int main()
{
    int i,n,currentTime=0;
    float avgTAT,avgWT;
    printf("Enter the no of processes: ");
    scanf("%d",&n);
    process a[n];
    printf("Enter id, arrival time and burst time of the processes: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i].id);
        scanf("%d",&a[i].at);   
        scanf("%d",&a[i].bt);
        a[i].rt=a[i].bt;
    }
    int completed=0;
    int totalWT=0;
    int totalTAT=0;
    while(completed<n)
    {
        // printf("Hi");
        int shortestJob=-1;
        int shortestTime = 99999;
        for(i=0;i<n;i++)
        {
            if(a[i].at <=currentTime && a[i].rt<shortestTime && a[i].rt >0)
            {
                shortestJob=i;
                shortestTime=a[i].rt;
            }
        }

        if(shortestJob==-1)
        {
            currentTime++;
        }
        else
        {
            a[shortestJob].rt--;
            currentTime++;
            if(a[shortestJob].rt==0)
            {
                completed++;
                a[shortestJob].tat=currentTime-a[shortestJob].at;
                a[shortestJob].wt=a[shortestJob].tat-a[shortestJob].bt;
                totalTAT+=a[shortestJob].tat;
                totalWT+=a[shortestJob].wt;
            }
        }
    }
    avgTAT = (float)totalTAT/n;
    avgWT = (float)totalWT/n;
    printf("\nID\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",a[i].id,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
    }
    printf("\nAverage Waiting Time = %f",avgWT);
    printf("\nAverage Turn Around Time = %f",avgTAT);
}
