#include "hsh.h"

/**
 * main - Simple Shell
 * @argc: input arguments
 * @argv: list of arguments
 * Return: values
 *
 */
int main(int argc, char *argv[])
{
	int status;

	signal(SIGINT, _siginthandler);
	status = _loop(argv);

	(void)argc;
	(void)argv;
	return (status);
}
