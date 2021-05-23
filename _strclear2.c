#define NULL ((void *)0)
char *_strpbrk(const char *str, char c);

/**
 * _strclear2 - edit the input str and remove the duplicated spaces
 * @str: input string, it must not be constant
 */
void _strclear2(char *const str)
{
	char *runner;
	const char *tokens = " \t";
	int i;

	if (!str)
		return;

	runner = str;
	while (_strpbrk(tokens, *runner))
		runner++;

	i = 0;
	while (*runner)
	{
		if (!_strpbrk(tokens, *runner))
		{
			str[i] = *runner;
			runner++;
			i++;
		}
		else
		{
			while (_strpbrk(tokens, *runner))
				runner++;
			if (*runner)
			{
				str[i] = ' ';
				i++;
			}
		}

	}
	str[i] = '\0';
}

/**
 * _strpbrk - search c in str
 * @str: input string, it must not be constant
 * @c: char
 * Return: ?
 */
char *_strpbrk(const char *str, char c)
{
	if (!str)
		return (NULL);

	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}

	return (NULL);
}

