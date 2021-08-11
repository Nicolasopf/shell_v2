#include "../hsh.h"

/**
 * _atoi - convert str into ingeter
 * @str: input str
 * Return: integer
 */

int _atoi(char *str)
{
	int n = 0; /* output */
	int sign = 1; /* sign multiplier 1/-1 */
	int i = 0; /* index for digit */

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i])
	{
		n = n * 10 + str[i] - '0';
		i++;
	}

	return (sign * n);
}

/**
 * _strcmp - compare two string
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if s1 == s2 or the substraction
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/**
 * _strcpy - a clone for strcpy
 * @dst: output
 * @src: input
 * Return: same outputf
 *
 */
char *_strcpy(char *dst, const char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dst[i] = src[i];
	dst[i] = '\0';

	return (dst);
}

/**
 * _strdup - string duplicated
 * @s: input string
 * Return: return a pointer to duplicated string or NULL if it fails
 *
 */
char *_strdup(const char *s)
{
	int len;
	char *output;

	len = 0;
	while (s[len])
		len++;

	output = malloc(sizeof(*output) * (len + 1));
	if (!output)
		return (NULL);

	for (len = 0; s[len]; len++)
		output[len] = s[len];
	output[len] = '\0';
	return (output);
}

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

#include "../hsh.h"

/**
 * _strncmp - compare two string
 * @s1: string 1
 * @s2: string 2
 * @n: number of parameters
 * Return: 0 if s1 == s2 or the substraction
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i + 1 < n)
		i++;
	return (s1[i] - s2[i]);

}
