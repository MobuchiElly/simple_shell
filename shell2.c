#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char *input = NULL;
    size_t input_size = 0;
    while (1) {
        char *prompt = "#cisfun$ ";
        write(STDOUT_FILENO, prompt, strlen(prompt));

        if (getline(&input, &input_size, stdin) == -1) {
            // Error reading input
            perror("getline");
            exit(EXIT_FAILURE);
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Exit program if user types "exit"
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Execute command using system()
        if (system(input) == -1) {
            perror("system");
            exit(EXIT_FAILURE);
        }
    }

    free(input);
    return 0;
}
