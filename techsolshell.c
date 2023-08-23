#include "techsol.h"

/**
 * endOfFile - function to handle end of file condition
 * @length: count returned by getline function
 * @buffer: the buffer to free at the end of file
 */
void endOfFile(int length, char *buffer)
{
	if (length == -1)
	{
		/* Check if input is from a terminal */
		if (isatty(0))
		{
			putStr("\n");
			free(buffer); /* Free the allocated buffer */
		}
		exit(0); /* Exit the shell */
	}
}

/**
 * handleSign - function to handle the SIGINT signal (Ctrl+C)
 * @number: signal number
 */
void handleSign(int number)
{
	if (number == SIGINT)
		putStr("\nTechsolShell$ "); /* Print a newline and the shell prompt */
}

/**
 * ourIsatty - function to print the shell prompt if in interactive mode
 */
void ourIsatty(void)
{
	if (isatty(0))
		putStr("TechsolShell$ "); /* Print the shell prompt */
}

/**
 * main - the main function to run the Techsol shell
 * Return: success (0)
 */
int main(void)
{
	size_t strLen = 0;
	int getlineBuff = 0;
	pathListLp *header = '\0';
	char **argv = NULL, *path = NULL, *envVal = NULL, *str = NULL;
	void (*func)(char **) = NULL;
	/* Register the handleSign function to handle SIGINT signal */
	signal(SIGINT, handleSign);

	while (1)
	{
		ourIsatty(); /* Print the shell prompt */
		fflush(stdin); /* Flush the input stream */
		getlineBuff = ourGetlineFunc(&str, &strLen, stdin); /* Get input from user */
		endOfFile(getlineBuff, str); /* Handle end of file condition */
		argv = strTokFunc(str, " \n");/* Tokenize the input string into an array */

		if (argv[0])
		{
			envVal = getEnviron("PATH");/* Get the value of PATH env var */
			/* Create a linked list of path directories from the PATH value */
			header = pathDirLink(envVal);
			/* Find the full path of the command using the linked list of directories */
			path = wchPath(argv[0], header);
			listFreed(header); /* Free the linked list of directories */
			func = inBuiltChk(argv); /* Check if the command is a built-in command */
			if (func)
				func(argv); /* Execute the built-in command */
			if (path)
			{
				free(argv[0]);
				argv[0] = path; /* Update the command with the full path */
			}
			exeFunc(argv); /* Execute the command */
		}
		else
			freeargv(argv); /* Free the argument array */
	}
	freeargv(argv), listFreed(header), free(str);/* Free allocated memory */
	return (0); /* Exit the shell with success status */
}

