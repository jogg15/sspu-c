#include <stdio.h>

int countDistinctNumbers(int n) {
    int used[10] = {0};

    while (n > 0) {
        const int digit = n % 10;
        used[digit] = 1;
        n /= 10;
    }

    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (used[i]) {
            count++;
        }
    }

    return count;
}

int main (void) {
    const int number = 1000;
    printf("Number of distinct digits: %d\n", countDistinctNumbers(number));
    return 0;
}
