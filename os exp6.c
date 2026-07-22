#include <stdio.h>

int main() {
    int n, bt[10], at[10], pr[10], rt[10];
    int ct[10], tat[10], wt[10];
    int complete = 0, time = 0, min, shortest;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        printf("P%d Arrival Burst Priority: ", i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    while(complete!=n) {
        min=9999;
        shortest=-1;

        for(int i=0;i<n;i++) {
            if(at[i]<=time && rt[i]>0 && pr[i]<min) {
                min=pr[i];
                shortest=i;
            }
        }

        if(shortest==-1){
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest]==0){
            complete++;
            ct[shortest]=time;
            tat[shortest]=ct[shortest]-at[shortest];
            wt[shortest]=tat[shortest]-bt[shortest];
        }
    }

    printf("\nP\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\n",i+1,ct[i],tat[i],wt[i]);

    return 0;
}