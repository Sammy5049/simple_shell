#include "techsol.h"

/**
 * executn - cmd execution.
 * @args: user arg array
 * @argv: cmd arg array
 * Author: TEchsol
 * Return: stat of the cmd
 */

int executn(char **args, char **argv)
{
	pid_t pid_tsol;
	int stat;

	pid_tsol = fork();
	if (pid_tsol < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	else if (pid_tsol == 0)
	{
		execve(args[0], args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&stat);
		if (WIFEXITED(stat))
			stat = WEXITSTATUS(stat);

		errno = stat;

		free(args); /*free malloc for strings*/
	}

	return (stat);
}



/**
 * executn_two - command two exec
 * @args: args array
 * @argv: cmd line array
 * @cmpcommand: complete command
 * Author: Techsol
 * Return: status
 */

int executn_two(char **args, char **argv, char *cmpcommand)
{
	pid_t pid_tsol;
	int stat;

	pid_tsol = fork();
	if (pid_tsol < 0)
	{
		perror(cmpcommand);
		exit(-1);
	}
	else if (pid_tsol == 0)
	{
		execve(cmpcommand, args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&stat);
		/*this Macro handles conversion of exit status */
		if (WIFEXITED(stat))
			stat = WEXITSTATUS(stat);
		errno = stat;

		free(cmpcommand);
		free(args);
	}
	return (stat);
}
