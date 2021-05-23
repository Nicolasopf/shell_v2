#include "hsh.h"
/**
 * _siginthandler - handler of INTSIGNAL
 * @num: code
 */
void _siginthandler(int num)
{
	char *msg = PROMPT;
	char c = '\n';

	write(0, &c, 1);
	write(0, msg, _strlen(msg));

	(void)num;
}
