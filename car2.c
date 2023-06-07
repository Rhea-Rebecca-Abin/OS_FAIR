#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_CARS 4
#define NUM_LANES 2

typedef struct {
    int id;
    int source_lane;
    int destination_lane;
} Car;

void simulateIntersection(Car* car) {
    // Approach intersection
    printf("Car %d approaching intersection from lane %d\n", car->id, car->source_lane);

    // Wait for other cars to clear the intersection
    sleep(car->id);

    // Cross intersection
    printf("Car %d crossing intersection from lane %d to lane %d\n", car->id, car->source_lane, car->destination_lane);
    sleep(1);

    // Exit intersection
    printf("Car %d has crossed the intersection\n", car->id);
}

int main() {
    Car cars[NUM_CARS];

    // Initialize cars
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].id = i;
        cars[i].source_lane = rand() % NUM_LANES;
        cars[i].destination_lane = rand() % NUM_LANES;
    }

    // Simulate intersection for each car
    for (int i = 0; i < NUM_CARS; i++) {
        simulateIntersection(&cars[i]);
    }

    return 0;
}

