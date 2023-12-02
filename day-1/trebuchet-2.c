#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY ' '

const char *NUMBERS_ARRAY[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

bool isNumber(const char input) {
    return input <= '9' && input >= '0';
}

int toNumber(const char c) {
    return c - '0';
}

int sumArray(const char acc[2]) {
    return toNumber(acc[0]) * 10 + toNumber(acc[1]);
}

char strToNumericChar(char buffer[6], int idx) {
    char cat[6];
    for (int i = 1; i < 6; i++) {
        cat[i - 1] = buffer[(i + idx) % 5];
    }
    for (short int i = 0; i < 9; i++) {
        char *aux = strstr(cat, NUMBERS_ARRAY[i]);
        int index = (aux - cat) / sizeof(char) - 1;
        if (aux != NULL) {
            buffer[(index + 2 + idx) % 5] = ' ';
            return i + 1 + '0';
        }
    }
    printf("Value does not contain a number. %s\n", buffer);
    exit(1);
}

bool isWrittenNumber(char buffer[6], int idx) {
    char cat[7];
    for (int i = 1; i < 6; i++) {
        cat[i - 1] = buffer[(i + idx) % 5];
    }
    for (int i = 0; i < 9; i++) {
        if (strstr(cat, NUMBERS_ARRAY[i]) != NULL) return true;
    }
    return false;
}

void assignLeftAndRight(char *l, char *r, char input) {
    if (*l != EMPTY) {
        *r = input;
        return;
    };
    *l = input;
    *r = input;
}

int main() {
    int sum = 0;
    char input, l = EMPTY, r;

    char buffer[6] = {' ', ' ', ' ', ' ', ' ', '\0'}; // max value is "eight\0"
    for (int i = 0; scanf("%c", &input) != EOF; i++) {
        buffer[i % 5] = input;
        if (isNumber(input)) {
            assignLeftAndRight(&l, &r, input);
            continue;
        }
        if (input == '\n') {
            char acc[2] = {l, r};
            sum += sumArray(acc);
            l = EMPTY;
            for (int i = 0; i < 5; i++) buffer[i] = ' ';
            buffer[5] = '\0';
            continue;
        }
        if (isWrittenNumber(buffer, i % 5)) {
            assignLeftAndRight(&l, &r, strToNumericChar(buffer, i % 5));
        }
    }
    printf("%d\n", sum);

    return 0;
}
