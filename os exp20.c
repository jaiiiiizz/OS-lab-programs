#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t wrt;

void *reader()
{
    printf("Reader is Reading\n");
    return NULL;
}

void *writer()
{
    sem_wait(&wrt);

    printf("Writer is Writing\n");

    sem_post(&wrt);

    return NULL;
}

int main()
{
    pthread_t r,w;

    sem_init(&wrt,0,1);

    pthread_create(&r,NULL,reader,NULL);
    pthread_create(&w,NULL,writer,NULL);

    pthread_join(r,NULL);
    pthread_join(w,NULL);

    sem_destroy(&wrt);

    return 0;
}