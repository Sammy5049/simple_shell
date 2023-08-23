#include "techsol.h"

/**
 * exeFunc - function to execute a command
 * @argv: argument array
 */
void exeFunc(char **argv)
{
	int condition;
	pid_t childpid;

	if (!argv || !argv[0])
		return;

	/* Creates a child process using fork */
	childpid = fork();
	if (childpid == -1)
		perror(getEnviron("_"));
	if (childpid == 0)
	{
		/* Execute the child process command */
		execve(argv[0], argv, environ);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}


	/* Clean up allocated memory and wait for the child till process finish */
	freeargv(argv);
	wait(&condition);
}

/**
 * redistribution - function to reallocate memory
 * @prept: pointer before realloc
 * @sizeBefore: size of pointer before realloc
 * @sizeAfter: size of pointer after realloc
 * Return: reallocated pointer
 */
void *redistribution(void *prept, size_t sizeBefore, size_t sizeAfter)
{
	size_t count;
	char *before = NULL, *after = NULL;

	if (!prept)
		return (ourCalloc(sizeAfter, 1));

	if (sizeAfter == sizeBefore)
		return (prept);

	if (sizeAfter == 0 && prept)
	{
		free(prept);
		return (NULL);
	}

	after = ourCalloc(sizeAfter, 1);
	before = prept;

	if (!after)
		return (NULL);
	if (sizeAfter > sizeBefore)
	{
		for (count = 0; count < sizeBefore; count++)
			after[count] = before[count];
		free(prept);

		for (count = sizeBefore; count < sizeAfter; count++)
			after[count] = '\0';
	}

	if (sizeAfter < sizeBefore)
	{
		for (count = 0; count < sizeAfter; count++)
			after[count] = before[count];
		free(prept);
	}
	return (after);
}

/**
 * ourCalloc - function to allocate memory with malloc and initialize to 0
 * @eleNum: number of elements
 * @sz: size of each element
 * Return: pointer to allocated memory
 */
void *ourCalloc(size_t eleNum, size_t sz)
{
	size_t count;
	char *buffer = NULL;

	if (eleNum == 0 || sz == 0)
		return (NULL);
	buffer = malloc(eleNum * sz);
	if (buffer)
	{
		for (count = 0; count < (eleNum * sz); count++)
			buffer[count] = 0;
		return (buffer);
	}
	else
		return (NULL);
}

/**
 * freeargv - custom function to free an array of pointers
 * @argv: pointer array
 */
void freeargv(char **argv)
{
	int count;

	/* Free each element in the pointer array andthe array itself */
	for (count = 0; argv[count]; count++)
		free(argv[count]);
	free(argv);
}

/**
 * strTokFunc - program to split strings and create an array of pointers
 * @string: string to split
 * @delimiter: separator for splitting
 * Return: pointer array
 */
char **strTokFunc(char *string, const char *delimiter)
{
	char **callArry = NULL;
	int count = 0, count1 = 0;
	char *callCpy = NULL, *strToken = NULL;

	/* Copy the input string to avoid changing the original */
	callCpy = ourCalloc((stringLen(string) + 1), 1);
	if (!callCpy)
	{
		perror(getEnviron("_"));
		return (NULL);
	}
	while (string[count])
	{
		callCpy[count] = string[count];
		count++;
	}
	callCpy[count] = '\0';

	/* Initialize the pointer array and tokenize the string */
	callArry = ourCalloc((sizeof(char *)), 1);
	strToken = strtok(callCpy, delimiter);
	callArry[0] = stringDup(strToken);

	count = 1;
	count1 = 2;

	/* Tokenize the string again and reallocate memory for the array */
	while (strToken)
	{
		strToken = strtok(NULL, delimiter);
		callArry = redistribution(
				callArry, (sizeof(char *) * (count1 - 1)), (sizeof(char *) * count1)
				);
		callArry[count] = stringDup(strToken);
		count++;
		count1++;
	}
	free(callCpy);
	return (callArry);
}
