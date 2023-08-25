#include "techsol.h"

/**
 * builtHandler - check if the cmd is builtin
 * @args: strg to check
 * @codename: prg name for the comd
 * @buff: buffer to get space alloc
 * Return: Execute cmd.
 */

int builtHandler(char **args, char *codename, char *buff)
{
	int position = 0, exec_cmd = 0;

	(void)codename;

	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(buff);
		exit(errno);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (environ[position] != NULL)
		{
			write(1, environ[position], strlen(environ[position]));
			write(1, "\n", 1);

			position++;
		}
		free(args);
		exec_cmd = 1;
	}

	return (exec_cmd);
}


/**
 * handleComment - program to know if commt was passed
 * @buff: str for fixxing the null byte
 * Author: TEchsol
 */

void handleComment(char *buff)
{
	int count = 0;

	while (buff[count])
	{
		if (count > 0 && buff[count] == '#' && buff[count - 1] != ' ')
			break;

		if (buff[count] == '#')
		{
			buff[count] = '\0';
			break;
		}

		count++;
	}
}
