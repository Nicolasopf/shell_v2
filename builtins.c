#include "hsh.h"

int _printenv(void);
int _bexit(char **argv);
int _chdir(char **argv);

/**
 * _builtins - check for builtins functions
 * @argv: input arguments
 * Return: 1=BREAK 2=CONTINUE 3=NOTFOUND
 */

int _builtins(char **argv)
{
	int status = NOTFOUND;
	char *cmd = argv[0];

	if (_strncmp(cmd, "exit", _strlen("exit")) == 0)
		status = _bexit(argv);
	else if (_strncmp(cmd, "cd", _strlen("cd")) == 0)
		status = _chdir(argv);
	else if (_strncmp(cmd, "env", _strlen("env")) == 0)
		status = _printenv();

	return (status);
}

/**
 * _chdir - change directory
 * @argv: arguments for the program
 * Return: BREAK=1 CONTINUE=2
 */

int _chdir(char **argv)
{
	int status = CONTINUE, print_old = 0;
	char *working_dir = _getenv("PWD"), *home = _getvalue("HOME");
	char *oldpwd = _getenv("OLDPWD"), *dst = argv[1], *cwd, actual_path[1024];

	globals()->program_status = 0;

	if (!dst || *dst == '~' || _strcmp(dst, "$HOME") == 0)
		dst = home;
	else if (_strcmp(dst, "-") == 0)
		print_old = 1, dst = oldpwd;

	oldpwd = _strcat(working_dir);
	status = chdir(dst);
	getcwd(actual_path, sizeof(actual_path));
	if (status != -1)
	{
		working_dir = _strdup(actual_path);
	}
	else
	{
		_perror(3, dst);
		globals()->program_status = 2;
	}


	if (print_old)
	{
		cwd = getcwd(NULL, 0);
		printf("%s\n", cwd);
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

	if (globals()->environ)
		for (i = 0; globals()->environ[i]; i++)
			printf("%s\n", globals()->environ[i]);
	return (CONTINUE);
}

/**
 * _bexit - builtin exit
 * @argv: arguments for the program
 * Return: BREAK=1 CONTINUE=2
 */
int _bexit(char **argv)
{
	int status, tmp;
	int *program_status = &globals()->program_status;

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
		_perror(2, argv[1]);
		*program_status = 2;
		status = CONTINUE;
	}
	return (status);
}
