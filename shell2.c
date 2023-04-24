#include "shell.h"

#define MAX_INPUT_SIZE 1024

int main() {
    char *input = NULL;
    size_t input_size = 0;
    while (1) {
        char *prompt = "#cisfun$ ";
        write(STDOUT_FILENO, prompt, _strlen(prompt));

        if (getline(&input, &input_size, stdin) == -1) {
            // Error reading input
            perror("getline");
            exit(EXIT_FAILURE);
        }

        // Remove newline character from input
        input[_strcspn(input, "\n")] = '\0';

        // Exit program if user types "exit"
        if (_strcmp(input, "exit") == 0) {
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
