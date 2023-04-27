#include "shell.h"

/**
 * _strcat - concatenates two strings
 *
 * @dest: the destination buffer
 * @src: the source string
 *
 * Return: pointer to destination buffer
 */

char *_strcat(char *dest, const char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';

	return (dest);
}
