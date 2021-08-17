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

/**
 * concat_env - concat two environment variables.
 * @env: environment variable to concat 1.
 * @value: enviroment variable to concat 2.
 * Return: the string concatenated.
 */

char *concat_env(char *env, char *value)
{
	unsigned int i, j;
	unsigned int char_counter = 0;
	char *new_env;

	char_counter = count_until_char(env, '=');
	char_counter += count_until_char(value, '\0');

	new_env = malloc(sizeof(char_counter) + 1);

	for (i = 0; env[i]; i++)
		new_env[i] = env[i];
	new_env[i++] = '=';
	for (j = 0; value[j]; j++, i++)
		new_env[i] = value[j];
	new_env[i] = '\0';

	printf("NEW %s\n", new_env);
	return (new_env);
}
