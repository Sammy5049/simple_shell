#include "techsol.h"

/**
 * main - main shell entry point
 * @argc: cmd line counter
 * @argv: vect
 * Return: the output err number
 *
 */

int main(int argc, char **argv)
{
	size_t sz_of_buf = 0;
	ssize_t number_rt = 0;
	int active = isatty(0);
	char *buf = NULL, **args = NULL, commandct, *completeCMD = NULL;
	int st_of_bltin = 0, counter = 0;
	errno = 0;

	(void)argc;
	while (1)
	{
		counter++;
		if (active == 1) /*prompt in inter-active mode*/
			write(1, "$ ", 2);

		number_rt = getline(&buf, &sz_of_buf, stdin);
		if (number_rt == -1)
		{
			free(buf);
			exit(errno);
		}
		handleComment(buf);
		args = handleTok(buf); /*allocated args*/
		if (args[0] == NULL)
		{
			free(args);
			continue;
		}
		/* Access returns -1 if path not found*/
		if (access(args[0], X_OK) == -1)
		{
			/* check if command is builtin or not*/
			st_of_bltin = builtHandler(args, argv[0], buf);

			if (st_of_bltin == 1)
				continue;

			/*give fullpath to it's own variable*/
			completeCMD = fullPathname(pathName(), args[0]);

			if (completeCMD == NULL)
			{
				commandct = (counter + '0'); /*Convert integer to character*/
				handleError(argv[0], commandct, args[0]);
				free(args);
				errno = 127; /*when not sys call, set errno to 127*/
				continue;
			}
			/* called when concat full path is valid*/
			executn_two(args, argv, completeCMD);
			continue;
			/*do not call next execution continue to top loop*/
		}
		/*check when pathname is entered the right way*/
		executn(args, argv);
	}

	return (errno);
}
