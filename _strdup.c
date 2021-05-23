#include <stdlib.h>
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
