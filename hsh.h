#ifndef _HSH_H_
#define _HSH_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define PROMPT "($): "

extern char **environ;


/* Strings folder: START */

/* string_utils.c */

size_t _strlen(const char *s);
int _atoi(char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dst, const char *src);
char *_strdup(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);

/* string_utils2.c */
char **_strsplit(char *str);
void _strclear2(char *const str);
char *_strclear(char const *str, char const *token);


/* Strings folder: END */



/*
 * Loop, read, run command, etc
 * FILE: loop.c
 */
int reader(char **line);
void loop(char **argv);
int run_command(char **input, char **argv);
int execute(char const *cmd, char *const *args);


/*
 * Which and helpers.
 */

char *which(char *cmd);


/*
 * Environment functions.
 */
char *_getenv(const char *pattern);


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


/**
 * struct global_s - global variables
 * @program_status: output of the program
 * @program_name: argv[0] of the program
 * @program_counter: conter of commands
 */
typedef struct global_s
{
	int program_status;
	int program_counter;
	char *program_name;
} global_t;

/**
 * enum CONSTANTS - constant from outputs
 * @SUCCESS: 0  return success from builtin
 * @NOTFOUND: builtin command not found
 * @BREAK: break  loop
 * @CONTINUE: continue loop
 */
enum CONSTANTS
{
	SUCCESS,
	BREAK,
	CONTINUE,
	NOTFOUND
};


global_t *globals(void);
int _perror(int error_message_code, char *argv);

#endif /* _HSH_H_ */
