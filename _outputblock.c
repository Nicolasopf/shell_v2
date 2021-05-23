#include "hsh.h"
/**
 * _outputblock - run the command and print
 * @input: input from _getline
 * @argv: values
 * @program_status: ?
 * @counter: ?
 * Return: 0=SUCCESS 1=BREAK 2=CONTINUE 3=NOTFOUND
 */
int _outputblock(char **input, int *program_status, char **argv, int *counter)
{
	char *line = *input;
	char *program = argv[0];
	char **cmd_argv, *full_path;
	int status = SUCCESS;

	cmd_argv = _strsplit(line);
	if (cmd_argv)
	{
		_strclear2(cmd_argv[0]);
		status = _builtins(cmd_argv, program_status, program, *counter);
		if (status == NOTFOUND)
		{
			full_path =  _which(cmd_argv[0]);
			if (full_path)
			{
				*program_status = 0;
				if (_runcmd(full_path, cmd_argv) != 0)
					*program_status = 2;
				free(full_path);
			}
			else
			{
				*program_status = 127;
				_perror(1, program, *counter, line);
			}
			status = CONTINUE;
		}
		free(cmd_argv);
	}
	return (status);
}
