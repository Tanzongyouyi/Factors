#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void print_factors(int number) {
    int *factors = (int *)malloc(number * sizeof(int));
    int factor_count = 0;

    for (int i = 1; i <= number; ++i) {
        if (number % i == 0) {
            int j;
            for (j = 0; j < factor_count; ++j) {
                if (factors[j] == i || factors[j] == number / i) {
                    break;
                }
            }
            if (j == factor_count) {
                factors[factor_count++] = i;
            }
        }
    }

    for (int i = 0; i < factor_count; ++i) {
        printf("%d ", factors[i]);
        printf("\n");
    }
    printf("%d\n", number);

    free(factors);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char command[MAX_INPUT_LENGTH];
    int number;

    while (1) {
        printf("> ");
        if (!fgets(input, MAX_INPUT_LENGTH, stdin)) {
            // Input error
            continue;
        }

        // Remove newline character if present
        input[strcspn(input, "n")] = 0;

        if (sscanf(input, "%s", command) != 1) {
            printf("Syntax errorn\n");
            continue;
        }

        if (strcmp(command, "factors") == 0) {
            if (sscanf(input, "%*s %d", &number) == 1) {
                print_factors(number);
            } else {
                printf("Syntax errorn\n");
            }
        } else if (strcmp(command, "help") == 0 || strcmp(command, "?") == 0) {
            printf("factors [A number] 来分解因数\n输入\"q\"或\"exit\"来退出\n谭总有一 2025 版权所有\n");
        } else if (strcmp(command, "q") == 0 || strcmp(command, "exit") == 0) {
	    printf("Copyright © 2025 Wave Studios. All rights reserved.\n");
            break;
        } else {
            printf("Syntax errorn\n");
        }
    }

    return 0;
}
