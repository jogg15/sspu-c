#include <stdio.h>

int main() {
    float height;
    float weight;
    float vysledek;

    printf("Zadej svoji vysku v metrech: ");
    scanf("%f", &height);

    printf("Zadej svoji vahu v kg: ");
    scanf("%f", &weight);

    vysledek = weight / (height * height);

    printf("Tve BMI je: %f", vysledek);

    return 0;
}
