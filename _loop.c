#include "hsh.h"

/**
 * _loop - a loop function
 * @argv: arguments of the program
 * Return: 1;
 */
int _loop(char **argv)
{
	char  *line = NULL;
	int counter = 0, status = 0, out_status;
	size_t n = 0;
	ssize_t bytes;

	while (1)
	{
		counter++;
		bytes = _inputblock(&line, &n);
		if (bytes == EOF)
			break;
		if (bytes == 1)
			continue;
		out_status = _outputblock(&line, &status, argv, &counter);
		if (out_status == BREAK)
			break;
		if (out_status == CONTINUE)
			continue;
	}
	free(line);
	return (status);
}
