#ifndef TECHSOL_H
#define TECHSOL_H




/* called system library functions */

#include <signal.h>
#include <stddef.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>


extern char **environ;


/**
 * struct getDetail - a pointer struct for getDetail variable
 * @argc: number of command line arguments
 * @envVariable: enviroment var
 * @argv: argument array
 * @change_env: the result of the env after it's changed
 */
typedef struct getDetail
{
	int argc;
	char **argv;
	char **envVariable;
	int change_env;
} getDetail;



/**
 * struct builtinCmdMb - a pointer struct for buildin cmd
 * @name1: the builtin84a3f6f5648d4d02e962 cmd to check
 * @func1: the function to execute builtin command
 */

typedef struct builtinCmdMb
{
	char *name1;
	void (*func1)(char **);
} builtinCmdMb;



/**
 * struct pathListLp -  path directories lists
 * @directory: path present in directory
 * @ptr: next in the node point
 */

typedef struct pathListLp
{
	char *directory;
	struct pathListLp *ptr;
} pathListLp;



/* List of function prototype delearation */
/*char *ourStringTok(contTokenizer *item, const char *delimiter);*/

/*void initialContTok(contTokenizer *item, char *str);*/
int unsetenvCase(getDetail *funcDet);
int ourUnsetEnv(getDetail *funcDet, char *variable);
int ourSetEnv(getDetail *funcDet, char *variable, char *variableVal);
int setenvCase(getDetail *funcDet);
ssize_t ourGetlineFunc(char **strptr, size_t *number, FILE *termread);
void (*inBuiltChk(char **argv))(char **argv);
pathListLp *appendEndNode(pathListLp **header, char *string);
void listFreed(pathListLp *header);
void *ourCalloc(size_t eleNum, size_t sz);
char *strConcat(char *string1, char *string2, char *string3);
pathListLp *pathDirLink(char *strPath);
char *wchPath(char *cmdName, pathListLp *header);
void *redistribution(void *preptr, size_t sizeBefore, size_t sizeAfter);
void freeargv(char **argv);
char *stringDup(char *string);
void exeFunc(char **argv);
void ourIsatty(void);
int _putchar(char ch);
int stringLen(char *string);
void handlerSign(int number);
void putStr(char *string);
void endOfFile(int length, char *buffer);
char *getEnviron(const char *globName);
char **strTokFunc(char *string, const char *delimiter);
void exitInBuilt(char **argv);
void currentEnv(char **argv);




#endif

