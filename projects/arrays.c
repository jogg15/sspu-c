#include <stdio.h>
#define SIZE 5

int main (void) {
    int a = 3, b = 5;
    printf("a = %d, b = %d\n",a , b);
    int tmp = a;
    a = b;
    b = tmp;

    printf("a = %d, b = %d\n",a , b);

    int array[SIZE] = { 1, 2 , 3, 4, 5};
    printf("size of int is %llu bytes.\n", sizeof(int));
    printf("size of array is %llu bytes.", sizeof(array));
    printf("Address of the beginning of the array is %p\n", array);


    printf("\n");


    for (int i = SIZE-1; i >= 0; i--) {
        printf("%3d ", array[i]);
    }

    // revers of array elements
    for (int i  = 0; i < SIZE / 2; i++) {
        tmp = array[i];
        array[i] = array[SIZE - 1];
        array[SIZE - 1] = tmp;
    }
    printf("Reverse elements:\n ");

    for (int i = 0; i < SIZE; i++) {
        printf("%3d ", array[i]);
    }
    printf("\n");

    int mass = 0;
    for (int i = 0; i < SIZE; i++) {
        mass += array[i];
    }
    printf("Sum of all elements: %d\n", mass);

    printf("Average of all elements: %f\n", (float)mass / SIZE);
    int min = array[0];
    int max = array[0];

    for (int i = 1; i < SIZE; i++) {
        if (array[i] > max ) {
            max = array[i];
        }

        if (array[i] < min ) {
            min = array[i];
        }
    }

    printf("Minimum is %d\n", min);
    printf("Maximum is %d\n", max);

    return 0;
}
