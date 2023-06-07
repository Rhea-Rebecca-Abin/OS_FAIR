#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *producer(void *arg);
void *consumer(void *arg);

int buffer[3];
int fill = 0;
int use = 0;

pthread_mutex_t mutex;
pthread_cond_t empty, full;

void put(int value) {
    buffer[fill] = value;
    fill = (fill + 1) % 3;
}

int get() {
    int tmp = buffer[use];
    use = (use + 1) % 3;
    return tmp;
}

void *producer(void *arg) {
    int i;
    for (i = 1; i <= 6; i++) {
        pthread_mutex_lock(&mutex);
        if (fill == 3) {
            printf("\nBuffer full. Producer waits.\n");
            pthread_cond_wait(&empty, &mutex);
        }
        put(i);
        printf("Producer produces item %d\n", i);
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *consumer(void *arg) {
    int i, item;
    for (i = 1; i <= 6; i++) {
        pthread_mutex_lock(&mutex);
        if (fill == 0) {
            printf("\nBuffer empty. Consumer waits.\n");
            pthread_cond_wait(&full, &mutex);
        }
        item = get();
        printf("Consumer consumes item %d\n", item);
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
}

int main() {
    pthread_t producer_id;
    pthread_t consumer_id;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&empty, NULL);
    pthread_cond_init(&full, NULL);

    pthread_create(&producer_id, NULL, producer, NULL);
    pthread_create(&consumer_id, NULL, consumer, NULL);

    pthread_join(producer_id, NULL);
    pthread_join(consumer_id, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&empty);
    pthread_cond_destroy(&full);

    return 0;
}

