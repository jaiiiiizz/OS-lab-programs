#include <stdio.h>

int main()
{
    int n = 5;

    for(int i=0;i<n;i++)
    {
        printf("Philosopher %d is Thinking\n",i);
        printf("Philosopher %d takes Fork %d and %d\n",i,i,(i+1)%5);
        printf("Philosopher %d is Eating\n",i);
        printf("Philosopher %d puts down forks\n\n",i);
    }

    return 0;
}