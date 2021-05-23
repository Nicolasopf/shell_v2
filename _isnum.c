/**
 * _isnum - check if a string is num
 * @str: input str
 * Return: 1 is str is a number or 0 if is not
 */

int _isnum(const char * const str)
{
	int i;
	const char *runner = str;

	if (*runner == '-')
		runner++;

	for (i = 0; runner[i]; i++)
		if (runner[i] < '0' || '9' < runner[i])
			return (0);
	return (1);
}
