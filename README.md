Simple shell project Collaborators: Damilola Adeola and Adeniji Mayokun

0x16. C - Simple Shell

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

0. Betty would be proud
Write a beautiful code that passes the Betty checks

1. Simple shell 0.1
execve will be the core part of your Shell, don’t forget to pass the environ to it…

2. Simple shell 0.2

Simple shell 0.2 +

Handle the PATH
fork must not be called if the command doesn’t exist

3.
Simple shell 0.3 +

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit
4.
Simple shell 0.4 +

Implement the env built-in, that prints the current environment

Simple shell 0.1 +

Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline
You don’t have to:

be able to move the cursor



7. Simple shell 0.2.1
#advanced
Simple shell 0.2 +

You are not allowed to use strtok



8. Simple shell 0.4.1
#advanced
Simple shell 0.4 +

handle arguments for the built-in exit
Usage: exit status, where status is an integer used to exit the shell


9. setenv, unsetenv
#advanced
Simple shell 1.0 +

Implement the setenv and unsetenv builtin commands

setenv
Initialize a new environment variable, or modify an existing one
Command syntax: setenv VARIABLE VALUE
Should print something on stderr on failure
unsetenv
Remove an environment variable
Command syntax: unsetenv VARIABLE
Should print something on stderr on failure

14. Variables
#advanced
Simple shell 1.0 +

Handle variables replacement
Handle the $? variable
Handle the $$ variable
Loving doing hard it.......
