#include "shell.h"

/**
 * _strcspn - function calculates length of initial segment of a string
 * containing chars not present in another substring being compared
 *
 * @a: string we are searching through
 *
 * @b: string containing chars to be excluded
 *
 * Return: length of initial segement of a containing none of the chars in b
 */

size_t _strcspn(const char *a, const char *b)
{
	size_t length;
	size_t n;

	length = 0;
	while (a[length] != '\0')
	{
		for (n = 0; b[n] != '\0'; n++)
		{
			if (a[length] == b[n])
			{
				return (length);
			}
		}
		length++;
	}
	return (length);
}
