#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_FILE "cisla.txt"
#define OUTPUT_FILE "hladiny.txt"
#define PI 3.14159265

typedef struct {
    double perimeter;
    double height;
    double volume;
} CONTAINER;

void header(void) {
    printf("V A L C E\n");
    printf("---------\n");
    printf("   polomer      vyska      objem valce    mnozstvi vody\n");
    printf("   (cm)         (cm)     (dm krychlove)      (litry)\n");
    printf("----------------------------------------------------------\n");
}

void file_header(FILE *output) {
    fprintf(output, "V A L C E  S  V Y H O V U J I C I M  O B J E M E M\n");
    fprintf(output, "--------------------------------------------------\n");
    fprintf(output, "  polomer    vyska    objem valce    mnozstvi vody   vyska hladiny\n");
    fprintf(output, "  (cm)       (cm)    (dm krychlove)        (litry)          (cm)\n");
    fprintf(output, "-------------------------------------------------------------------\n");
}

double calculate_volume(double perimeter, double height) {
    return (PI * perimeter * perimeter * height) / 1000.0;
}

double calculate_level(double perimeter, double water_volume) {
    return (water_volume * 1000.0) / (PI * perimeter * perimeter);
}

int main() {
    CONTAINER container;
    int count = 0;
    int output_count = 0;

    FILE *input = fopen(INPUT_FILE, "r");
    if (input == NULL) {
        printf("Cannot open input file: %s\n", INPUT_FILE);
        return 1;
    }

    FILE *output = fopen(OUTPUT_FILE, "w");
    if (output == NULL) {
        printf("Cannot open output file: %s\n", OUTPUT_FILE);
        fclose(input);
        return 1;
    }

    header();
    file_header(output);

    while(fscanf(input, "%lf %lf %lf", &container.perimeter, &container.height, &container.volume) == 3) {
        count++;
        double volume = calculate_volume(container.perimeter, container.height);

        printf("%2d. %6.0f cm %8.0f cm %10.2f dm %11.0f l\n",
            count, container.perimeter, container.height, volume, container.volume);

        if (container.volume <= volume * 1000.0) {
            output_count++;
            double level = calculate_level(container.perimeter, container.volume);

            fprintf(output, "%2d. %5.0f cm %7.0f cm %11.2f dm %12.0f l %11.2f cm\n",
                output_count, container.perimeter, container.height, volume, container.volume, level);
        }
    }

    printf("----------------------------------------------------------\n");
    fprintf(output, "-------------------------------------------------------------------\n");

    fclose(input);
    fclose(output);

    printf("Output file '%s' has been created\n", OUTPUT_FILE);

    return 0;
}

// cisla.txt
// 22  63 62
// 48   8 47
// 43  54 77
// 19  75 35
// 29  12 75
// 13  55 64
// 17  77 11
// 48  15 57
// 34  77 95
// 23  45 83
