/**
 * _strcpy - a clone for strcpy
 * @dst: output
 * @src: input
 * Return: same outputf
 *
 */
char *_strcpy(char *dst, const char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dst[i] = src[i];
	dst[i] = '\0';

	return (dst);
}

