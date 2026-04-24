// still TODO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIGIT_NUMBER 20

void array_reverse(int array[DIGIT_NUMBER]) {
    for (int i = DIGIT_NUMBER - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
}

void array_fill(int array[DIGIT_NUMBER]) {
    for (int i = 0; i < DIGIT_NUMBER; i++) {
        array[i] = rand() % DIGIT_NUMBER;
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main() {
    srand((unsigned) time(NULL));

    int array[DIGIT_NUMBER];
    array_fill(array);
    array_reverse(array);
    return 0;
}
