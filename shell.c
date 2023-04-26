#include "shell.h"

/**
 * main - main function for the shell loop
 *
 * Return: return 0 success
 */

int main(void)
{
        char *text = NULL;
        size_t text_size = 0;

        while (1)
        {
                char *loop_prompt = "#cisfun$ ";
                char *command = NULL;
                char *command_path = NULL;
                char *token = NULL;
                char **args = NULL;

                write(STDOUT_FILENO, loop_prompt, _strlen(loop_prompt));

                if (getline(&text, &text_size, stdin) == -1)
                {
                        perror("getline error");
                        exit(EXIT_FAILURE);
                }

                text[_strcspn(text, "\n")] = '\0';

                if (_strcmp(text, "exit") == 0)
                {
                        free(text);
                        exit(EXIT_SUCCESS);
                }

                command = strtok(text, " ");
                command_path = _getenv("PATH");
                token = strtok(command_path, ":");

                while (token)
                {
                        char *full_path = malloc(_strlen(token) + _strlen(command) + 2);
                        if (!full_path)
                        {
                                perror("malloc error");
                                exit(EXIT_FAILURE);
                        }
                        _strcpy(full_path, token);
                        _strcat(full_path, "/");
                        _strcat(full_path, command);

                        if (access(full_path, F_OK) != -1)
                        {
                                args = malloc(sizeof(char *) * 3);
                                if (!args)
                                {
                                        perror("malloc error");
                                        exit(EXIT_FAILURE);
                                }

                                args[0] = command;
                                args[1] = strtok(NULL, "");
                                args[2] = NULL;

                                if (fork() == 0)
                                {
                                        if (execve(full_path, args, NULL) == -1)
                                        {
                                                perror("execve error");
                                                exit(EXIT_FAILURE);
                                        }
                                }
                                else
                                {
                                        wait(NULL);
                                }

                                free(args);
                                free(full_path);
                                break;
                        }

                        free(full_path);
                        token = strtok(NULL, ":");
                }

                if (!token)
                {
                        printf("%s: command not found\n", command);
                }
        }

        free(text);
        return (0);
}
