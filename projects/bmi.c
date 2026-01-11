#include <stdio.h>

int main() {
    float height;
    float weight;

    printf("Zadej svoji vysku v metrech: ");
    scanf(" %f", &height);

    printf("Zadej svoji vahu v kg: ");
    scanf(" %f", &weight);

    const float vysledek = weight / (height * height);

    printf("Tve BMI je: %f\n", vysledek);

    return 0;
}
