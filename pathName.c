#include "techsol.h"


/**
 * tokenizePathnames - output pathname tokenized
 * @pathnames: all directory in path
 * Return: tok pathname
 */

char **tokenizePathnames(char *pathnames)
{
	char *changed = NULL, *tokenizer = NULL;
	char **tokPath = NULL;
	int position = 0;

	if (pathnames == NULL)
		return (NULL);

	changed = strtok(pathnames, "=");
	changed = strtok(NULL, "=");

	tokPath = malloc(sizeof(char *) * 30);
	if (tokPath == NULL)
		return (NULL);

	tokenizer = strtok(changed, ":");
	while (tokenizer != NULL)
	{
		tokPath[position] = tokenizer;
		tokenizer = strtok(NULL, ":");
		position++;
	}
	tokPath[position] = NULL; /* Array holding all directories */

	return (tokPath);
}





/**
 * fullPathname - output pathname if exit
 * @pathnames: all directory in path
 * @command: string of cmd
 * Return: NULL or full_pathname in str
 */

char *fullPathname(char *pathnames, char *command)
{
	char **tokPath = NULL, *pathnameFull = NULL;
	int position = 0;
	size_t str_length = 0;

	tokPath = tokenizePathnames(pathnames);
	if (tokPath == NULL)
		return (NULL);

	while (tokPath[position] != NULL)
	{
		str_length = strlen(tokPath[position]) + strlen(command) + 2;
		pathnameFull = malloc(str_length);
		if (pathnameFull == NULL)
		{
			free(tokPath);
			return (NULL);
		}
		strcpy(pathnameFull, tokPath[position]);
		strcat(pathnameFull, "/");
		strcat(pathnameFull, command);

		if (access(pathnameFull, X_OK) == 0)
		{
			free(tokPath);
			return (pathnameFull);
		}
		free(pathnameFull);
		pathnameFull = NULL;
		position++;
	}

	free(tokPath);
	return (NULL);
}

