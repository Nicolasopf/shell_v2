#include "hsh.h"
int _noneedpath(char const *str);
int _getpath(path_t **head);
path_t *_addnode(path_t **head, char *str);
void _freepath(path_t *head);

/**
 * which - locate the command
 * @cmd: command to search
 * Return: full path of the program, It needs to free
 */
char *which(char *cmd)
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

/**
 * _getpath - get linked list of the PATH variable
 * @head: reference of the list's head
 * Return: 0 if  it works, Another num if it fails
 */
int _getpath(path_t **head)
{
	char *path_str;
	char *buffer, *runner;
	int buffer_size, i, j;

	path_str = _getenv("PATH");
	if (!path_str)
		return (1);

	buffer_size = _strlen(path_str) + 1;

	buffer = malloc(sizeof(*buffer) * (buffer_size));
	if (!buffer)
		return (2);

	runner = path_str;
	for (i = j = 0; i < buffer_size; i++)
	{
		buffer[j] = runner[i];
		if (runner[i] == '\0' || runner[i] == ':')
		{
			buffer[j] = '\0';
			_addnode(head, buffer);
			j = 0;
			continue;
		}
		j++;
	}

	free(buffer);
	return (0);
}

/**
 * _addnode - add node at the head of the list
 * @head: pointer to the head of the list
 * @str: value of the node;
 * Return: new node or NULL if fail
 */
path_t *_addnode(path_t **head, char *str)
{
	char *copy;
	path_t *node, *runner;

	node = malloc(sizeof(*node));
	copy = _strdup(str);
	node->val = copy;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	runner = *head;
	while (runner->next)
		runner = runner->next;
	runner->next = node;
	return (node);
}

/**
 * _freepath - free linked list
 * @head: head of list
 */
void _freepath(path_t *head)
{
	path_t *killer;

	if (!head)
		return;

	while ((killer = head) != NULL)
	{
		head = head->next;
		free(killer->val);
		free(killer);
	}
}
