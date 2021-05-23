#include "hsh.h"
/**
 * _runcmd - fork process and execve
 * @cmd: list of comand and arguments
 * @args: list of comand and arguments
 * Return: 0
 */

int _runcmd(char const *cmd, char *const *args)
{
	int status = 0;
	pid_t my_pid;

	my_pid = fork(); /* my_pid@child = 0; my_pid@parent = my_pid@child*/
	if (my_pid == 0)
	{
		status = execve(cmd, args, environ);
		exit(status);
	}
	else
	{
		waitpid(my_pid, &status, 0);
		if (status)
		{
			return (1);
		}
	}
	return (0);
}

