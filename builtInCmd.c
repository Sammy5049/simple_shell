#include "techsol.h"

/**
 * builtHandler - check if the cmd is builtin
 * @args: strg to check
 * @codename: prg name for the comd
 * @buff: buffer to get space alloc
 * description: TECHSOL
 * Return: Execute cmd.
 */

int builtHandler(char **args, char *codename, char *buff)
{
	int position = 0, exec_cmd = 0;

	(void)codename;

	if (strCmp(args[0], "exit") == 0)
	{
		free(args);
		free(buff);
		exit(errno);
	}
	else if (strCmp(args[0], "env") == 0)
	{
		while (environ[position] != NULL)
		{
			write(1, environ[position], strLen(environ[position]));
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

/**
 * strLen - count chars and return numb
 * @s: data from user input
 * Return: The result
 */
int strLen(char *s)
{
 int count = 0, length = 0;

 while (s[count++])
 {
  length++;
 }

 return (length);
}




/**
 * strCmp - Compares two str
 * @s1: first str thst s2 is compared with
 * @s2: second str compared with s1
 *
 * Return: return the true is not same and false
 */


int strCmp(char *s1, char *s2)
{
	int count = 0;

	while (s1[count] != '\0' && s2[count] != '\0')
	{
		if (s1[count] != s2[count])
		{
			return (s1[count] - s2[count]);
		}
		count++;
	}
	return (s1[count] - s2[count]);
}
