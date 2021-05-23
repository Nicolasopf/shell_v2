#include "hsh.h"
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

	copy = _strdup(str);
	if (!copy)
		return (NULL);

	tmp = copy;
	n = 0;
	while (_strtok(tmp, delim))
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
		list[i] = _strtok(tmp, delim);
		tmp = NULL;
	}
	list[i] = NULL;

	return (list);
}
