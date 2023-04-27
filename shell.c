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

		if (system(text) == -1)
		{
			perror("system");
			exit(EXIT_FAILURE);
		}
	}

	free(text);
	return (0);
}
