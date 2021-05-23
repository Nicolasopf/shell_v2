#include "hsh.h"
/**
 * _getenv - get enviroment from a variable
 * @pattern: input
 * Return: return program
 */
char *_getenv(const char *pattern)
{
	int i, len;

	len = _strlen(pattern);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(pattern, environ[i], len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}

	return (NULL);
}
