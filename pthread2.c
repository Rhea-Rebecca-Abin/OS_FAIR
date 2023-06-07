#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *producer(void *arg);
void *consumer(void *arg);
void wait(int*);
void signal(int*);

int mutex = 1, full = 0, empty = 3, x = 0;

int main()
{
    pthread_t producer_id;
    pthread_create(&producer_id, NULL, producer, NULL);

    pthread_t consumer_id;
    pthread_create(&consumer_id, NULL, consumer, NULL);

    pthread_join(producer_id, NULL);
    pthread_join(consumer_id, NULL);

    return 0;
}

void wait(int* s)
{
    (*s)--;
}

void signal(int* s)
{
    (*s)++;
}

void *producer(void *arg)
{
    while (1)
    {
        if (mutex == 0)
        {
            printf("\nWaiting for other process");
        }
        else if (empty == 0)
        {
            printf("\nBuffer full");
        }
        else
        {
            wait(&mutex);
            signal(&full);
            wait(&empty);
            x++;
            printf("\nproducer produces the item %d", x);
            signal(&mutex);
        }
        sleep(1);
    }
}

void *consumer(void *arg)
{
    while (1)
    {
        if (mutex == 0)
        {
            printf("\nWaiting for other process");
        }
        else if (full == 0)
        {
            printf("\nBuffer empty");
        }
        else
        {
            wait(&mutex);
            wait(&full);
            signal(&empty);
            printf("\nconsumer consumes item %d", x);
            x--;
            signal(&mutex);
        }
        sleep(2);
    }
}

