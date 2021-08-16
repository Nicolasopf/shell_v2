#include "../hsh.h"
char *_strpbrk(const char *str, char c);

/**
 * _strsplit - string split into a list
 * @str: input string
 * Return: string splited
 */

char **_strsplit(char *str)
{
	char **list;
	char *copy;
	char *tmp;
	char const *delim = " \t";
	int i, n;

	if (!str)
		return (NULL);

	copy = strdup(str);
	if (!copy)
		return (NULL);

	tmp = copy;
	n = 0;
	while (strtok(tmp, delim))
	{
		n++;
		tmp = NULL;
	}
	free(copy);
	if (n == 0)
		return (NULL);

	list = malloc(sizeof(*list) * (n + 1));
	if (!list)
		return (NULL);

	tmp = str;
	for (i = 0; i < n; i++)
	{
		list[i] = strtok(tmp, delim);
		tmp = NULL;
	}
	list[i] = NULL;

	return (list);
}

/**
 * _strclear2 - edit the input str and remove the duplicated spaces
 * @str: input string, it must not be constant
 */
void _strclear2(char *const str)
{
	char *runner;
	const char *tokens = " \t";
	int i;

	if (!str)
		return;

	runner = str;
	while (_strpbrk(tokens, *runner))
		runner++;

	i = 0;
	while (*runner)
	{
		if (!_strpbrk(tokens, *runner))
		{
			str[i] = *runner;
			runner++;
			i++;
		}
		else
		{
			while (_strpbrk(tokens, *runner))
				runner++;
			if (*runner)
			{
				str[i] = ' ';
				i++;
			}
		}

	}
	str[i] = '\0';
}

/**
 * _strpbrk - search c in str
 * @str: input string, it must not be constant
 * @c: char
 * Return: ?
 */


char *_strpbrk(const char *str, char c)
{
	if (!str)
		return (NULL);

	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}

	return (NULL);
}

/**
 * _strclear - remove start and end characters (needs free)
 * @str: input
 * @token: char to ignore ant start and end
 * Return: NULL if fails, or new strings if works
 *
 */
char *_strclear(char const *str, char const *token)
{
	int len, i, j, k, found;
	char *output;

	len = _strlen(str);
	output = malloc(len + 1);
	if (output != NULL)
	{
		for (i = j = 0; i < len; i++)
		{
			for (found = k = 0; token[k] && !found;  k++)
				if (str[i] == token[k])
					found = 1;

			if (!found)
			{
				output[j] = str[i];
				j++;
			}
		}
		output[j] = '\0';
	}
	return (output);

}

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
