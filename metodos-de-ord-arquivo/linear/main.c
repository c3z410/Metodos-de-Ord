#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "countings.h"
#include "radixs.h"

#define FILENAME "couting.txt"

void printarray(int* arr, size_t length) {
    printf("%d", arr[0]);
    for (size_t i = 1; i < length; i++) {
        printf(", %d", arr[i]);
    }
    printf("\n");
}

int main() {
    FILE* f = fopen(FILENAME, "r");
    int* arr = malloc(50000 * sizeof(int));
    char* line = NULL;
    size_t len = 0;
    struct timespec tstart={0,0}, tend={0,0};

    int i;
    for (i = 0; getline(&line, &len, f) != -1; i++) {
        int n = atoi(line);
        arr[i] = n;
    }

    fclose(f);

    arr = realloc(arr, i * sizeof(int));


    printf("Array original: \n");
    printarray(arr, i);

    clock_gettime(CLOCK_MONOTONIC, &tstart);
    //countings(arr, i);
    radixs(arr, i);
    clock_gettime(CLOCK_MONOTONIC, &tend);

    printf("\nArray ordenado: ");
    printarray(arr, i);
    printf("\nTempo: %.5f segundos\n", ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

    free(arr);

    return 0;
}
