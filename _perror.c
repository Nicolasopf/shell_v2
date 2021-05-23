#include "hsh.h"
#include <stdarg.h>
/**
 * _perror - print errors
 * @code: code of the error
 * Code Description:
 * 001 - shell, command not found (code, program, counter, args1)
 * 002 - exit, invalid arg (code, program, counter, args1)
 * 003 - cd, failed (code, program, counter, args1)
 * Return: ?
 *
 */
int _perror(int code, ...)
{
	int status = 0;
	const char *fmt;
	va_list args;
	const char *str[10];
	int num[10];
	const char * const msg[] = {
		"NO ERRORS",
		"%s: %d: %s: not found\n",
		"%s: %d: exit: Illegal number: %s\n",
		"%s: %d: cd: can't cd to %s\n",
		NULL
	};

	va_start(args, code);
	switch (code)
	{
		case (1): case (2): case (3):
			fmt = msg[code];
			str[0] = va_arg(args, char*);
			num[0] = va_arg(args, int);
			str[1] = va_arg(args, char*);
			fprintf(stderr, fmt,
					str[0],
					num[0],
					str[1]
					);
			break;
		default:
			break;
	}
	va_end(args);
	return (status);
}
