#include <stdio.h>

#define MIN_YEAR 1900
#define MAX_YEAR 2030
#define COLUMNS 8
#define TXTFILE "years.txt"

int bufferControl () {
    int buffer = 0;

    while (getchar() != '\n') {
        buffer++;
    } return buffer;
}

int getYear( ) {
    int year;
    int buffer;

    do {
        printf("Zadej rok v intervalu od %d do %d:\n", MIN_YEAR, MAX_YEAR);
        scanf("%d", &year);

        buffer = bufferControl();

        if (buffer != 0) {
            printf("Spatne zadani.\n");
        }

        else if (year > MAX_YEAR || year < MIN_YEAR) {
            printf("Chybny rok. Zadej znova.");
        }
    } while (buffer != 0 || year > MAX_YEAR || year < MIN_YEAR);

    return year;
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void listYears (int year, FILE *fw) {
    fprintf(fw,"%5d%c", year, isLeapYear(year) ? '*': ' ');
}

void listEnter (FILE *fw) {
    fprintf(fw, "\n");
}

int main(void) {
    int count = 0;

    FILE *file;
    file = fopen(TXTFILE, "w");

    if (file == NULL) {
        printf("Soubor %s se neotevrel - MODE: W", TXTFILE);
    }

    for (int year = getYear(); year <= MAX_YEAR; year++) {

        listYears(year, file);
        listYears(year, stdout);
        count++;

        if (count % COLUMNS == 0) {
            listEnter(file);
            listEnter(stdout);
        }
    }

    listEnter(stdout);

    if (fclose(file) == EOF) {
        printf("Soubor %s nebyl uspesne uzavren.", TXTFILE);
    } else {
        printf("Soubor %s se spravne otevrel.", TXTFILE );
    }
}
