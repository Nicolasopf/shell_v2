#include "hsh.h"

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
