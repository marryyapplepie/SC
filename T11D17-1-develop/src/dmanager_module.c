#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void swap(int* xp, int* yp);
void sort(struct door* doors);
void output(struct door* doors);
void status_closed(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors);
    status_closed(doors);
    output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(struct door* doors) {
    int i, j;
    for (i = 0; i < DOORS_COUNT - 1; i++) {
        int swapped = 1;
        for (j = 0; j < DOORS_COUNT - i - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                swap(&doors[j].id, &doors[j + 1].id);
                swapped = 0;
            }
        }
        if (swapped == 1) break;
    }
}

void status_closed(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}
