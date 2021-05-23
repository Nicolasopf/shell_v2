#include <stdio.h>
/**
 * _getline - this is call getline and remove the newline
 * @lineptr: pointer to line
 * @n: size
 * @stream: output file
 * Return: size ot line
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{

	return (getline(lineptr, n, stream));
}
