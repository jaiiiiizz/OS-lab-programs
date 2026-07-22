#include<stdio.h>

int main()
{
    int users,files;

    printf("Enter number of users: ");
    scanf("%d",&users);

    for(int i=0;i<users;i++)
    {
        printf("\nUser %d\n",i+1);

        printf("Number of files: ");
        scanf("%d",&files);

        for(int j=0;j<files;j++)
        {
            char name[20];
            printf("File %d: ",j+1);
            scanf("%s",name);
        }
    }

    return 0;
}