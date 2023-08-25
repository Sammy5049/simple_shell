#include "techsol.h"



/**
 * handleInput - func to get line from terminal input
 * @counter: line counter
 * Description: TECHSOL
 * Return: the buffer
 *
 */
char *handleInput(int *counter)
{
	size_t sz_of_buf = 0;
	ssize_t number_rt = 0;
	int active = isatty(0);
	char *buf = NULL;

	if (active == 1) /*prompt in inter-active mode*/
		write(1, "$Techsol ", 9);

	number_rt = getline(&buf, &sz_of_buf, stdin);
	if (number_rt == -1)
	{
		free(buf);
		exit(errno);
	}

	(*counter)++;
	handleComment(buf);
	return (buf);
}


/**
 * executeCommands - fucnt to check command execution
 * @args: string input
 * @argv: array of arg ptr
 * Description: TECHSOL
 */

void executeCommands(char **args, char **argv)
{
	int counter = 0;
	char *completeCMD = NULL;
	char commandct;

	while (1)
	{
		char *buf = handleInput(&counter);

		args = handleTok(buf);
		if (args[0] == NULL)
		{
			free(args);
			continue;
		}

		if (access(args[0], X_OK) == -1)
		{
			int st_of_bltin = builtHandler(args, argv[0], buf);

			if (st_of_bltin == 1)
				continue;

			completeCMD = fullPathname(pathName(), args[0]);

			if (completeCMD == NULL)
			{
				commandct = (counter + '0');
				handleError(argv[0], commandct, args[0]);
				free(args);
				errno = 127;
				continue;
			}

			executn_two(args, argv, completeCMD);
		}
		else
			executn(args, argv);
	}
}







/**
 * main - main shell entry point
 * @argc: cmd line counter
 * @argv: vect
 * Description: TECHSOL
 * Return: the output err number
 *
 */
int main(int argc, char **argv)
{
	errno = 0;

	(void)argc;

	executeCommands(NULL, argv);

	return (errno);
}

