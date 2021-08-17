#include "../hsh.h"

/**
 * _isnum - check if a string is num
 * @str: input str
 * Return: 1 is str is a number or 0 if is not
 */

int _isnum(const char * const str)
{
	int i;
	const char *runner = str;

	if (*runner == '-')
		runner++;

	for (i = 0; runner[i]; i++)
		if (runner[i] < '0' || '9' < runner[i])
			return (0);
	return (1);
}

/**
 * copy_pointer_array - double array to copy.
 * @double_array: double array to copy.
 */


void copy_pointer_array(char **double_array)
{
	unsigned int i;

	globals()->environ = malloc(256);
	for (i = 0; double_array[i]; i++)
		globals()->environ[i] = _strdup(double_array[i]);
	globals()->environ[i + 1] = NULL;
}


/**
 * count_until_char - count includes characters
 * @string: string to search
 * @character: character a buscar
 * Return: number of eachs character includes
 */

int count_until_char(char *string, char character)
{
	if (!string || !*string)
		return (0);

	if (*string != character)
		return (1 + count_until_char(string + 1, character));

	return (count_until_char(string + 1, character));
}


/**
 * _strcat - concatenates two strings.
 * @destination: string to destinate
 * @source: source.
 * Return: string.
 */

char *_strcat(char *destination, const char *source)
{
	char *ptr = destination + strlen(destination);

	while (*source != '\0')
		*ptr++ = *source++;
	*ptr = '\0';
	return (destination);
}
