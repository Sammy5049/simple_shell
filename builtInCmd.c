#include "techsol.h"

/**
 * _atoi - function to convert string to integer
 * @str: string pointer
 * Return: return converted integer
 */
int _atoi(char *str)
{
	int count = 0, convInt = 0, intSign = 1;

	/*Skip non-numeric characters and handle signs*/
	while (!((str[count] >= '0') && (str[count] <= '9')) && (str[count] != '\0'))
	{
		if (str[count] == '-')
			intSign = intSign * (-1);
		count++;
	}

	/*Convert numeric characters to an integer*/
	while ((str[count] >= '0') && (str[count] <= '9'))
	{
		convInt = (convInt * 10) + (intSign * (str[count] - '0'));
		count++;
	}

	return (convInt);
}

/**
 * exitInBuilt - shell exit and return status
 * @argv: entered word array
 */
void exitInBuilt(char **argv)
{
	int noWords = 0, count = 0;

	if (argv[1])
	{
		/*Convert the second argument to an integer for exit status*/
		noWords = _atoi(argv[1]);
		if (noWords <= -1)
			noWords = 2;

		/*Clean up allocated memory and exit with the status*/
		freeargv(argv);
		exit(noWords);
	}

	/* Clean up allocated memory and exit with the status 0*/
	for (count = 0; argv[count]; count++)
		free(argv[count]);
	free(argv);
	exit(0);
}

/**
 * currentEnv - program to return the current environment variables
 * @argv: entered word array (unused in this function)
 */
void currentEnv(char **argv __attribute__((unused)))
{
	int count;

	/* Loop through and print the environment variable*/
	for (count = 0; environ[count]; count++)
	{
		putStr(environ[count]);
		putStr("\n");
	}
}

/**
 * inBuiltChk - function to discover built-in commands
 * @argv: argument array to be checked
 * Return: return pointer to a function if found, else return 0
 */
void (*inBuiltChk(char **argv))(char **argv)
{
	int count = 0, count2 = 0;

	/* List of built-in command and their corresponding functions */
	builtinCmdMb accessories[] = {
		{"exit", exitInBuilt},
		{"env", currentEnv},
		{NULL, NULL}
	};

	/* Iterate through the list of built-in commands and find a match */
	for (count = 0; accessories[count].name1; count++)
	{
		if (accessories[count].name1[count2] == argv[0][count2])
		{
			for (count2 = 0; argv[0][count2]; count2++)
			{
				/* Compare the given command name characters */
				if (accessories[count].name1[count2] != argv[0][count2])
					break;
			}

			/* If the entire command name matches, and return*/
			if (!argv[0][count2])
				return (accessories[count].func1);
		}
	}

	/* Return 0 if no built-in command was found */
	return (0);
}

