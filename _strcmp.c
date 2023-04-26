#include "shell.h"

/**
 * _strcmp - function compares two strings
 *
 * @a:the first string to be compared
 *
 * @b: the second string to be compared
 *
 * Return: return 0 if strings are equal else returns difference in strings
 */

int _strcmp(const char *a, const char *b)
{
	int n;

	n = 0;

	while (a[n] != '\0' && b[n] != '\0')
	{
		if (a[n] != b[n])
		{
			return (a[n] - b[n]);
		}
	n++;
	}
	return (a[n] - b[n]);
}
