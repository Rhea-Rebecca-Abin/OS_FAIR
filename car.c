#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_CARS 4
#define NUM_LANES 2

pthread_mutex_t intersection_mutex;

typedef struct {
    int id;
    int source_lane;
    int destination_lane;
} Car;

void* simulateIntersection(void* arg) {
    Car* car = (Car*)arg;

    // Approach intersection
    printf("Car %d approaching intersection from lane %d\n", car->id, car->source_lane);

    // Wait for mutex lock
    pthread_mutex_lock(&intersection_mutex);

    // Cross intersection
    printf("Car %d crossing intersection from lane %d to lane %d\n", car->id, car->source_lane, car->destination_lane);
    sleep(1);

    // Release mutex lock
    pthread_mutex_unlock(&intersection_mutex);

    // Exit intersection
    printf("Car %d has crossed the intersection\n", car->id);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_CARS];
    Car cars[NUM_CARS];

    // Initialize mutex
    pthread_mutex_init(&intersection_mutex, NULL);

    // Initialize cars
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].id = i;
        cars[i].source_lane = rand() % NUM_LANES;
        cars[i].destination_lane = rand() % NUM_LANES;
    }

    // Create threads for each car
    for (int i = 0; i < NUM_CARS; i++) {
        pthread_create(&threads[i], NULL, simulateIntersection, (void*)&cars[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_CARS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&intersection_mutex);

    return 0;
}

