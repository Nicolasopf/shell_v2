#include "hsh.h"
int _noneedpath(char const *str);

/**
 * _which - locate the command
 * @cmd: command to search
 * Return: full path of the program, It needs to free
 */
char *_which(char *cmd)
{
	char *full_path = NULL;
	path_t *path_list = NULL, *runner;
	char  *copy_cmd;
	int len;
	int status;

	if (cmd == NULL || *cmd == '\0')
		return (NULL);

	copy_cmd = _strclear(cmd, " \t");
	if (!_noneedpath(copy_cmd) && access(copy_cmd, X_OK) == 0)
		return (copy_cmd);

	status = _getpath(&path_list);
	if (status == 0)
	{
		runner = path_list;
		while (runner)
		{
			len = _strlen(runner->val) + _strlen("/") + _strlen(copy_cmd);
			full_path = malloc(sizeof(*full_path) + (len + 1));
			_strcpy(full_path, runner->val);
			if (*full_path != '\0')
				_strcpy(full_path + _strlen(full_path), "/");
			_strcpy(full_path + _strlen(full_path), copy_cmd);
			if (access(full_path, X_OK) == 0)
				break;
			free(full_path);
			full_path = NULL;
			runner = runner->next;
		}
		_freepath(path_list);
	}
	free(copy_cmd);
	return (full_path);
}

/**
 * _noneedpath - check if the command don't need a path
 * @str: command
 * Return: 0 if don't need a path or 1 if it's NULL or 2 if it don't found
 */
int _noneedpath(char const *str)
{
	int len;

	if (!str)
		return (1);

	len = _strlen(str);

	if (str[0] == '/')
		return (0);

	if (len < 2)
		return (1);

	if (str[0] == '.' && str[1] == '/')
		return (0);

	if (len < 3)
		return (1);

	if (str[0] == '.' && str[1] == '.' && str[2]  == '/')
		return (0);

	return (2);
}
