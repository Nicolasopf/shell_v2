#include "../hsh.h"

/**
 * _getenv - get enviroment from a variable
 * @pattern: input
 * Return: return program
 */

char *_getenv(const char *pattern)
{
	int i, len;

	len = _strlen(pattern);

	for (i = 0; globals()->environ[i]; i++)
		if (_strncmp(pattern, globals()->environ[i], len) == 0
			&& globals()->environ[i][len] == '=')
			return (globals()->environ[i]);

	return (NULL);
}

/**
 * _getvalue - get the value of an enviroment variable.
 * @env: environment variable to get value
 * Return: The value or NULL.
 */

char *_getvalue(char *env)
{
	unsigned int i = 0;

	for (i = 0; env[i]; i++)
		if (env[i] == '=')
			return (env + i + 1);

	return ('\0');
}
