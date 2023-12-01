#include <stdbool.h>
#include <stdio.h>

#define EMPTY ' '

bool isNumber(const char input) {
    return input <= '9' && input >= '0';
}

int toNumber(const char c) {
    return c - '0';
}

int sumArray(const char acc[2]) {
    return toNumber(acc[0]) * 10 + toNumber(acc[1]);
}

int main() {
    int sum = 0;
    char input, l = EMPTY, r;

    while (scanf("%c", &input) != EOF) {
        if (isNumber(input)) {
            if (l != EMPTY) {
                r = input;
                continue;
            };
            l = input;
            r = input;
            continue;
        }
        if (input == '\n') {
            char acc[2] = {l, r};
            sum += sumArray(acc);
            l = EMPTY;
        }
    }
    printf("%d\n", sum);

    return 0;
}
