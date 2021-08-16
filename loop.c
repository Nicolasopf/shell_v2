#include "hsh.h"

/**
 * loop - Initialize an infinite loop for the prompt
 * @argv: Argument vectors.
 */

void loop(char **argv)
{
	char *line = NULL;
	int *cmd_counter, bytes, loop_status;
	size_t n = 0;

	cmd_counter = &globals()->program_counter;
	while (1)
	{
		(*cmd_counter)++;
		bytes = reader(&line, &n);
		if (bytes == EOF)
			break;
		if (bytes == 1)
			continue;
		loop_status = run_command(&line,  argv);
		if (loop_status == BREAK)
			break;
		if (loop_status == CONTINUE)
			continue;
	}
	free(line);
}

/**
 * reader - Read a line from stdin.
 * @line: Line where to put the stdin.
 * Return: Size of bytes read.
 */

int reader(char **line, size_t *n)
{
	int bytes;
	char *runner;

	if (isatty(STDIN_FILENO))
		printf("%s", PROMPT);

	bytes = getline(line, n, stdin);
	if (bytes == EOF)
	{
		if (isatty(STDIN_FILENO))
			puts("");
	}
	else
	{
		runner = *line;
		while (*runner)
		{
			if (*runner == '\n')
				*runner = '\0';
			runner++;
		}
	}

	return (bytes);
}

/**
 * run_command - run the command and print to stdout.
 * @input: input from _getline
 * @argv: values
 * Return: 0=SUCCESS 1=BREAK 2=CONTINUE 3=NOTFOUND
 */
int run_command(char **input, char **argv)
{
	char *line = *input;
	char **cmd_argv, *full_path;
	int status = SUCCESS, *program_status = &globals()->program_status;

	(void) argv;

	cmd_argv = _strsplit(line);
	if (cmd_argv)
	{
		_strclear2(cmd_argv[0]);
		status = _builtins(cmd_argv);
		if (status == NOTFOUND)
		{
			full_path = which(cmd_argv[0]);
			if (full_path)
			{
				*program_status = 0;
				if (execute(full_path, cmd_argv) != 0)
					*program_status = 2;
				free(full_path);
			}
			else
			{
				*program_status = 127;
				_perror(1, line);
			}
			status = CONTINUE;
		}
		free(cmd_argv);
	}

	return (status);
}

/**
 * execute - fork process and execve
 * @cmd: list of comand and arguments
 * @args: list of comand and arguments
 * Return: 0
 */

int execute(char const *cmd, char *const *args)
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
			return (1);
	}
	return (0);
}
