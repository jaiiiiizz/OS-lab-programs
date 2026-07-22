#include <stdio.h>

int main() {
    int n, bt[10], rt[10], wt[10], tat[10], tq;
    int time=0, remain;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    remain=n;

    for(int i=0;i<n;i++) {
        printf("Burst Time P%d: ",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    while(remain!=0) {
        for(int i=0;i<n;i++) {
            if(rt[i]>0) {
                if(rt[i]<=tq) {
                    time+=rt[i];
                    wt[i]=time-bt[i];
                    rt[i]=0;
                    remain--;
                }
                else {
                    time+=tq;
                    rt[i]-=tq;
                }
            }
        }
    }

    printf("\nP\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++) {
        tat[i]=bt[i]+wt[i];
        printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }

    return 0;
}