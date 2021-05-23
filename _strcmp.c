/**
 * _strcmp - compare two string
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if s1 == s2 or the substraction
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);

}
