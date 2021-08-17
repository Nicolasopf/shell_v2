# Shell

The Thompson shell was the first Unix shell, introduced in the first version of Unix in 1971, and was written by Ken Thompson at Bell Labs.  
In this project is implemented a version of the shell in C programming language. 

Basically the shell is a bucle. Once and once again the shell shows a prompt on the screen, receives input from the keyboard, parse it and execute it as a command. 

The shell creation implies managing system calls as fork, execve, wait, and exit (between many);  the manipulation of the environment variables as path, pwd and oldpwd; and the management of pipelines and redirections.

The main challenge about the shell is sending information to each function for the error messages printing. We managed to implement static variables.

The new challenge were the implementation of the redirections and pipelines.

### Builtins included
- cd / cd [path] / cd -
Changes the current directory of the process, and update the environment variables related.
- exit / exit [error code] 
Quit from the shell. Send an error code to the standard error if it is given.
- env
Prints the environment variables.
- setenv
Initialize a new environment variable, or modify an existing one.
- unsetenv
Remove a environment variable.

### Compilation

Make file command compiles the program (using gcc 4.8.4) and all its depencies.

````
make
````

### Use

````
./hsh
````

### Environment

Ubuntu 14.04 LTS
