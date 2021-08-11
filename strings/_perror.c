#include "../hsh.h"
/**
 * _perror - print error message
 * @error_message_code: selector for template of messages
 * @argv: output extra infromation
 * Return: Always 0
 */
int _perror(int error_message_code, char *argv)
{
	const char *template_list[] = {
		"NO ERRORS",
		"%s: %d: %s: not found\n",
		"%s: %d: exit: Illegal number: %s\n",
		"%s: %d: cd: can't cd to %s\n",
		"%s: %d: Command syntax: %s VARIABLE VALUE\n",
		NULL
	};

	fprintf(stderr, template_list[error_message_code],
			globals()->program_name,
			globals()->program_counter,
			argv);

	return (0);
}
