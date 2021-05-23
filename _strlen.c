#include <stdio.h>
#include "hsh.h"

/**
 * _strlen - clone of strlen
 * @s: string input
 * Return: len of the s
 */
size_t _strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
