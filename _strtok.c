#include <string.h>
/**
 * _strtok - extract tokens from string
 * @str: input string, if it's NULL it could use previus call
 * @delim: delimitors
 * Return: a pointer to the copy element
 */
char *_strtok(char *str, const char *delim)
{
	return (strtok(str, delim));
}
