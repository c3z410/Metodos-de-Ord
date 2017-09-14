#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "merges.h"
#include "quicks.h"
#include "heaps.h" 

#define FILENAME "num.10000.2.in"

void print_array(int* arr, size_t length) {
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

    
    print_array(arr, i);

    clock_gettime(CLOCK_MONOTONIC, &tstart);
    mergesort(arr, 0 , i);
    //quicksort(arr, 0 , i);
    //heapsort(arr, i);
    clock_gettime(CLOCK_MONOTONIC, &tend);

    printf("\nArray ordenado: ");
    print_array(arr, i);
    printf("\nTempo: %.5f segundos\n", ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

    free(arr);

    return 0;
}
