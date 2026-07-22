#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t empty,full;

void *producer()
{
    printf("Produced Item\n");
    sem_post(&full);
    return NULL;
}

void *consumer()
{
    sem_wait(&full);
    printf("Consumed Item\n");
    return NULL;
}

int main()
{
    pthread_t p,c;

    sem_init(&full,0,0);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    sem_destroy(&full);

    return 0;
}