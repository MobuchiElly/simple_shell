#include "shell.h"

/**
 * _getenv - gets the value of the environment variable "name"
 * @name: name of the environment variable
 *
 * Return: On success, the value of the environment variable. Otherwise, NULL.
 */

char *_getenv(const char *name)
{
	char *result;

	char *path = NULL;
	int i = 0, j = 0, k = 0;
	size_t len = _strlen(name);

	while (environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
		{
			path = environ[i] + len + 1;
			break;
		}
		i++;
	}

	if (path == NULL)
	return (NULL);

	result = malloc(sizeof(char) * _strlen(path) + 1);

	while (path[j])
	{
		if (path[j] == ':')
		{
			result[k++] = '/';
		}
		result[k++] = path[j++];
	}
	result[k] = '\0';

	return (result);
}
