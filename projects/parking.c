#include <stdio.h>

#define FREE_HOURS 2
#define RATE 20
#define INPUT_FILE "casy.txt"
#define OUTPUT_FILE "platby.txt"

typedef struct {
    int h, m, s;
} Time;

typedef struct {
    Time in, out;
} Record;

int to_seconds(Time t) {
    return t.h * 3600 + t.m * 60 + t.s;
}

Time to_time(int sec) {
    Time t = {sec / 3600, (sec % 3600) / 60, sec % 60};
    return t;
}

int price(Time over) {
    if (over.m || over.s) over.h++;
    return over.h * RATE;
}

int main() {
    FILE *in = fopen(INPUT_FILE, "r");
    FILE *out = fopen(OUTPUT_FILE, "w");

    if (!in || !out) {
        printf("File error.\n");
        return 1;
    }

    Record r;
    int i = 0, j = 0;

    printf("Parking\n-----------------------------\n");

    fprintf(out, "Parking Payments\n");
    fprintf(out, "Free hours: %d, Rate: %d CZK\n\n", FREE_HOURS, RATE);

    while (fscanf(in, "%d %d %d %d %d %d",
                  &r.in.h, &r.in.m, &r.in.s,
                  &r.out.h, &r.out.m, &r.out.s) == 6) {

        int total_sec = to_seconds(r.out) - to_seconds(r.in);
        Time total = to_time(total_sec);

        printf("%d. %02d:%02d:%02d -> %02d:%02d:%02d = %02d:%02d:%02d\n",
               ++i,
               r.in.h, r.in.m, r.in.s,
               r.out.h, r.out.m, r.out.s,
               total.h, total.m, total.s);

        int limit = FREE_HOURS * 3600;

        if (total_sec > limit) {
            Time over = to_time(total_sec - limit);

            fprintf(out, "%d. %02d:%02d:%02d -> %02d:%02d:%02d | Over: %02d:%02d:%02d | %d CZK\n",
                    ++j,
                    r.in.h, r.in.m, r.in.s,
                    r.out.h, r.out.m, r.out.s,
                    over.h, over.m, over.s,
                    price(over));
        }
    }

    fclose(in);
    fclose(out);

    printf("Output file created.\n");
    return 0;
}
