#include "shell.h"

/**
 * _strncmp - compare the first n bytes of two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of bytes to compare
 *
 * Return: 0 if the strings are equal, less than 0 if s1 is less than s2,
 * greater than 0 if s1 is greater than s2
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	if (i == n)
		return (0);

	return (s1[i] - s2[i]);
}
