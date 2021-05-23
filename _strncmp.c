#include "hsh.h"
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
	{
		i++;
	}
	return (s1[i] - s2[i]);

}
