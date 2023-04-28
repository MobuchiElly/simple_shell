#include "shell.h"

/**
 * main - main function for the shell loop
 *
 * Return: return 0 success
 */

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	pid_t child_pid;
	int status;

	while (1)
	{
		char *prompt = "#cisfun$ ";

		write(STDOUT_FILENO, prompt, _strlen(prompt));

		if (getline(&input, &input_size, stdin) == -1)
		{
			perror("getline error");
			exit(EXIT_FAILURE);
		}

		input[_strcspn(input, "\n")] = '\0';

		if (_strcmp(input, "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		char *token = strtok(input, " ");
		char **args = malloc(sizeof(char *) * (MAX_INPUT_SIZE / 2));
		if (args == NULL)
		{
			perror("malloc error");
			exit(EXIT_FAILURE);
		}

		int i = 0;
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		if (_strcmp(args[0], "cd") == 0)
		{
			if (args[1] == NULL)
			{
				chdir(_getenv("HOME"));
			}
			else
			{
				if (chdir(args[1]) == -1)
				{
					perror("cd");
				}
			}
		}
		else if (_strcmp(args[0], "echo") == 0)
		{
			for (int j = 1; args[j] != NULL; j++)
			{
				write(STDOUT_FILENO, args[j], _strlen(args[j]));
				if (args[j + 1] != NULL)
				{
					write(STDOUT_FILENO, " ", 1);
				}
			}
			write(STDOUT_FILENO, "\n", 1);
		}
		else if (_strcmp(args[0], "pwd") == 0)
		{
			char *cwd = getcwd(NULL, 0);
			if (cwd == NULL)
			{
				perror("getcwd");
				exit(EXIT_FAILURE);
			}
			write(STDOUT_FILENO, cwd, _strlen(cwd));
			write(STDOUT_FILENO, "\n", 1);
			free(cwd);
		}
		else
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}

			if (child_pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					perror("execvp");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				waitpid(child_pid, &status, 0);
			}
		}

		free(args);
	}

	free(input);
	return (0);
}
