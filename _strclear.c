#include "hsh.h"
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
