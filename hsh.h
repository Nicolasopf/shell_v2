#ifndef _HSH_H_
#define _HSH_H_
#include <stdio.h> /* printf/puts */
#include <stdlib.h> /* malloc/free/exit */
#include <unistd.h> /* access/execve/fork/isatty/chdir */
#include <sys/wait.h> /* wait  */

#define MAGENTA "\033[35m"
#define RSTFMT "\033[0m"
#define PROMPT MAGENTA "jgsh$ " RSTFMT
#define SUCCESS 0
#define BREAK 1
#define CONTINUE 2
#define NOTFOUND 3

extern char **environ;

/**
 * struct path_s - linked list of path
 * @val: path name
 * @next: next of path
 */
typedef struct path_s
{
	char *val;
	struct path_s *next;
} path_t;

char **_strsplit(char *);
char *_getenv(const char *);
char *_strclear(char const *str, char const *token);
char *_strcpy(char *, char *);
char *_strdup(const char *);
char *_strtok(char *, const char *);
char *_which(char *);
int _atoi(char *str);
int _builtins(char **argv, int *status, char *program, int counter);
int _getpath(path_t **head);
int _isnum(const char * const str);
int _loop(char **);
int _outputblock(char **input, int *program_status, char **argv, int *counter);
int _perror(int code, ...);
int _runcmd(char const *, char *const *);
int _strcmp(const char *, const char *);
int _strncmp(const char *, const char *, size_t);
path_t *_addnode(path_t **head, char *str);
size_t _strlen(const char *);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
ssize_t _inputblock(char **line, size_t *);
void _freepath(path_t *head);
void _siginthandler(int);
void _strclear2(char *str);

#endif /* _HSH_H_ */
