#include <stdio.h>

#define SIZE 5

int main(void) {
    int values[2] = {3, 5};

    printf("a = %d, b = %d\n", values[0], values[1]);

    int tmp = values[0];
    values[0] = values[1];
    values[1] = tmp;

    printf("a = %d, b = %d\n", values[0], values[1]);

    int array[SIZE] = {1, 2, 3, 4, 5};

    printf("size of int is %llu bytes.\n", sizeof(int));
    printf("size of array is %llu bytes.\n", sizeof(array));
    printf("Address of the beginning of the array is %p\n", (void*)array);

    printf("\nOriginal reversed print:\n");
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%3d ", array[i]);
    }

    for (int i = 0; i < SIZE / 2; i++) {
        tmp = array[i];
        array[i] = array[SIZE - 1 - i];
        array[SIZE - 1 - i] = tmp;
    }

    printf("\nReversed array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%3d ", array[i]);
    }
    printf("\n");

    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    printf("Sum of all elements: %d\n", sum);
    printf("Average of all elements: %f\n", (float)sum / SIZE);

    int min = array[0];
    int max = array[0];

    for (int i = 1; i < SIZE; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }

    printf("Minimum is %d\n", min);
    printf("Maximum is %d\n", max);

    return 0;
}
