#include "../hsh.h"

/**
 * free_environ - Free the environ variable.
 */

void free_environ(void)
{
	unsigned int i;

	for (i = 0; globals()->environ[i]; i++)
		free(globals()->environ[i]);

	free(globals()->environ);
}
