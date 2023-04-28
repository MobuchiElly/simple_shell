#include "shell.h"

/**
 * print_loop_prompt - prints the loop prompt
 *
 * Return: void
 */
void print_loop_prompt(void)
{
    char *loop_prompt = "$ ";

    if (isatty(STDIN_FILENO))
    {
        write(STDOUT_FILENO, loop_prompt, _strlen(loop_prompt));
    }
}

/**
 * read_command - reads command from stdin
 *
 * Return: pointer to string
 */
char *read_command(void)
{
    char *text = NULL;
    size_t text_size = 0;

    if (getline(&text, &text_size, stdin) == -1)
    {
        perror("getline error");
        exit(EXIT_FAILURE);
    }

    text[_strcspn(text, "\n")] = '\0';

    return text;
}

/**
 * run_command - runs command using system call
 * @command: command to run
 *
 * Return: void
 */
void run_command(char *command)
{
    if (system(command) == -1)
    {
        perror("system");
        exit(EXIT_FAILURE);
    }
}

/**
 * process_input - processes input from stdin
 * @text: pointer to string of input
 *
 * Return: void
 */
void process_input(char *text)
{
    char *command;

    if (_strcmp(text, "exit") == 0)
    {
        free(text);
        exit(EXIT_SUCCESS);
    }
    if (!isatty(STDIN_FILENO))
    {
        while (*text == ' ' || *text == '\t')
        {
            text++;
        }
        run_command(text);
        free(text);
        exit(EXIT_SUCCESS);
    }

    command = strtok(text, " ");
    if (_strcmp(command, "ls") == 0)
    {
        command = "/bin/ls";
    }
    run_command(command);
}

/**
 * main - main function for the shell loop
 *
 * Return: return 0 success
 */
int main(void)
{
    char *text = NULL;

    while (1)
    {
        print_loop_prompt();
        text = read_command();
        process_input(text);
    }
    free(text);
    return (0);
}
