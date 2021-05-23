#include "hsh.h"
/**
 * _inputblock - print PROMPT and get stdin
 * @line: input line
 * @n: size of variable
 * Return: bytes readed
 */

ssize_t _inputblock(char **line, size_t *n)
{
	int bytes;
	char *runner;

	if (isatty(STDIN_FILENO))
		printf("%s", PROMPT);

	bytes = _getline(line, n, stdin);
	if (bytes == EOF)
	{
		if (isatty(STDIN_FILENO))
			puts("");
	}
	else
	{
		runner = *line;
		while (*runner)
		{
			if (*runner == '\n')
				*runner = '\0';
			runner++;
		}
	}

	return (bytes);
}
