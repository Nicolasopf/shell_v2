#include "hsh.h"
int _printenv(void);
int _bexit(char **argv, int *program_status, char *program, int counter);
int _chdir(char **argv, int *program_status, char *program, int counter);
/**
 * _builtins - check for builtins functions
 * @argv: input arguments
 * @program_status: the status of exit
 * @program: ?
 * @counter: ?
 * Return: 1=BREAK 2=CONTINUE 3=NOTFOUND
 */
int _builtins(char **argv, int *program_status, char *program, int counter)
{
	int status = NOTFOUND;
	char *cmd = argv[0];

	if (_strncmp(cmd, "exit", _strlen("exit")) == 0)
	{
		status = _bexit(argv, program_status, program,  counter);
	}
	else if (_strncmp(cmd, "cd", _strlen("cd")) == 0)
	{
		status = _chdir(argv, program_status, program,  counter);
	}
	else if (_strncmp(cmd, "env", _strlen("env")) == 0)
	{
		status = _printenv();
	}
	return (status);
}

/**
 * _chdir - change directory
 * @argv: arguments for the program
 * @program_status: status of the shell (for errors)
 * @program: name of the shell (for errors)
 * @counter: shell counter (for errors)
 * Return: BREAK=1 CONTINUE=2
 */
int _chdir(char **argv, int *program_status, char *program, int counter)
{
	int status = CONTINUE;
	int print_old = 0;
	char *working_dir = _getenv("PWD");
	char *home = _getenv("HOME");
	char *old = _getenv("OLDPWD");
	char *dst = argv[1];
	char *cwd;

	*program_status = 0;
	if (!dst)
		dst = home;
	else if (_strcmp(dst, "-") == 0)
	{
		print_old = 1;
		dst = old;
	}

	if (dst)
	{
		status = chdir(dst);
		if (status != -1)
		{
			_strcpy(working_dir, dst);
		}
		else
		{
			_perror(3, program, counter, dst);
			*program_status = 2;
		}
	}
	if (print_old)
	{
		cwd = getcwd(NULL, 0);
		puts(cwd);
		free(cwd);
	}
	return (status);
}
/**
 * _printenv - print environment
 * Return: 1=CONTINUE
 */
int _printenv(void)
{
	int i;

	if (environ)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
	}

	return (CONTINUE);
}
/**
 * _bexit - builtin exit
 * @argv: arguments for the program
 * @program_status: status of the shell (for errors)
 * @program: name of the shell (for errors)
 * @counter: shell counter (for errors)
 * Return: BREAK=1 CONTINUE=2
 */
int _bexit(char **argv, int *program_status, char *program, int counter)
{
	int status, tmp;

	status = BREAK;
	if (argv[1])
	{
		if (_isnum(argv[1]))
		{
			tmp = _atoi(argv[1]);
			*program_status = tmp;
			if (tmp >= 0)
				return (BREAK);
		}
		_perror(2, program, counter, argv[1]);
		*program_status = 2;
		status = CONTINUE;
	}
	return (status);
}
