#include <stdio.h>

#define SOUBOR "cisla.txt"

int main (void) {
    FILE *fp = fopen(SOUBOR, "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    double cislo, nejvetsi;
    
    if (fscanf(fp, "%lf", &nejvetsi) != 1) {
        printf("Soubor %s je prazdny.\n", SOUBOR);
        fclose(fp);
        return 1;
    }

    while (fscanf(fp, "%lf", &cislo) == 1) {
        if (cislo > nejvetsi) {
            nejvetsi = cislo;
        }
    }

    fclose(fp);
    printf("Nejvetsi cislo je %lf", nejvetsi);
    return 0;
}
