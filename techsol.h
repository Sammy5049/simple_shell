#ifndef TECHSOL_H
#define TECHSOL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>


extern char **environ;


/* Variable prototypes*/
int strLen(char *s);
int strCmp(char *s1, char *s2);
int strnCmp(char *s1, char *s2, size_t n);
char *strDup(char *string);
char *strCpy(char *dest, char *src);
char *strCat(char *dest, char *src);
void executeCommands(char **args, char **argv);
char *handleInput(int *counter);
char **tokenizePathnames(char *pathnames);
int executn(char **args, char **argv);
int executn_two(char **args, char **argv, char *cmpcommand);
char *fullPathname(char *pathnames, char *command);
char *pathName(void);
void handleComment(char *buff);
int builtHandler(char **args, char *codename, char *buff);
char **handleTok(char *str);
/*ssize_t ourGetlineFunc(char **strptr, size_t *number, FILE *termread)*/



/* functions to handle err*/
void handleError(char *program, int counter, char *cmdcnt);
void putstr(char *string);
int _putchar(char c);
void arg_free(int argc, char *argv[]);




#endif
