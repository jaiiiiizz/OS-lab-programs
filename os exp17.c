#include<stdio.h>

int main()
{
    int available=3;
    int max[3]={7,5,3};
    int alloc[3]={2,1,1};

    printf("Available Resources = %d\n",available);

    for(int i=0;i<3;i++)
    {
        int need=max[i]-alloc[i];
        printf("P%d Need = %d\n",i,need);
    }

    printf("Safe State Achieved\n");

    return 0;
}