#include "hsh.h"

/**
 * main - main file for shell_v2
 * @argc: argument counter
 * @argv: aguments for the shell
 * Return: 0
*/
int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;


	globals()->program_name = argv[0];
	loop(argv);

	return (globals()->program_status);
}
