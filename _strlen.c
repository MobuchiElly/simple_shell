#include "shell.h"

/**
 * _strlen - function returns length of a string
 *
 * @s: the string whose length is to be returned
 *
 *Return: length of string s
 */

int _strlen(const char *s)
{
	int length;
	const char *b;

	b = s;
	length = 0;

	while (*b != '\0')
	{
		length++;
		b++;
	}
	return (length);
}
