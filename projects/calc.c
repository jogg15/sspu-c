#import <stdio.h>
#import <float.h>

int main () {
    char znamenko;
    double vysledek, x, y;

    printf("Zadej znamenko [+, -, *, /]: ");
    scanf(" %c", &znamenko);

    printf("Zadej dve cislice: ");
    scanf(" %lf %lf", &x, &y);

    switch (znamenko) {
        case '+':
            vysledek = x + y;
            break;
        case '-':
            vysledek = x - y;
            break;
        case '*':
            vysledek = x * y;
            break;
        case '/':
            vysledek = x / y;
            break;
        default:
            printf("Neplatne znamenko.\n");
            return 1;
    }
        printf("%.2lf\n", vysledek);
    return 0;
}