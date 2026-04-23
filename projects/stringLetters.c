#include <stdio.h>
#include <ctype.h>

#define STRING_BUFFER_SIZE 1024
#define LETTERS 26

#define stringize(s) #s
#define tostring(s) stringize(s)

size_t readString(char* array) {
    printf("Enter an input string with up to " tostring(STRING_BUFFER_SIZE) " characters:\n");
    for (size_t i = 0; i < STRING_BUFFER_SIZE; i++) {
        int c = getchar();

        if (c == EOF || c == '\n') {
            return i;
        }

        array[i] = (char) toupper(c);
    }

    return 0;
}

void countLetters(const char* array, size_t arraySize, int* counts) {
    for (size_t i = 0; i < arraySize; i++) {
        char c = array[i];
        if (c >= 'A' && c <= 'Z') {
            c -= 'A';
            counts[c] += 1;
        }
    }
}

void printLetterCounts(int* counts) {
    for (size_t i = 0; i < LETTERS; i++) {
        char currentCharacter = i + 'A';
        if (counts[i] != 0) {
            printf("%c: %d\n", currentCharacter, counts[i]);
        }
    }
}

int main(void) {
    char string[STRING_BUFFER_SIZE];
    int counts[LETTERS] = {0};
    size_t bufferSize = readString(string);

    countLetters(string, bufferSize, counts);
    printLetterCounts(counts);

    return 0;
}
