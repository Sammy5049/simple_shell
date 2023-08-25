#include "techsol.h"

/**
 * tokenizePathnames - output pathname tokenized
 * @pathnames: all directory in path
 * Description: TECHSOL
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
 * Description: TECHSOL
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
		str_length = strLen(tokPath[position]) + strLen(command) + 2;
		pathnameFull = malloc(str_length);
		if (pathnameFull == NULL)
		{
			free(tokPath);
			return (NULL);
		}
		strCpy(pathnameFull, tokPath[position]);
		strCat(pathnameFull, "/");
		strCat(pathnameFull, command);

		if (access(pathnameFull, X_OK) == 0)
		{
			free(tokPath);
			free(pathnames);
			return (pathnameFull);
		}

		free(pathnameFull);
		position++;
	}

	free(tokPath);
	free(pathnames);
	return (NULL);
}


/**
 * strCat - concat two strs
 * @dest: first chara to conct
 * @src: second char to concat
 * Return: Return dest
 */


char *strCat(char *dest, char *src)
{
	int pos1;
	int pos2;

	pos1 = 0;

	while (dest[pos1] != '\0')
	{
		pos1++;
	}

	pos2 = 0;

	while (src[pos2] != '\0')
	{
		dest[pos1] = src[pos2];
		pos1++;
		pos2++;
	}
	dest[pos1] = '\0';

	return (dest);
}




/**
* strCpy - copy str and return the dest
* @dest: inputed val src
* @src: inputed val src
* Return: the destination
*/
char *strCpy(char *dest, char *src)
{
	int Pos = 0;

	int count = 0;

	while (*(src + Pos) != '\0')
		Pos++;
	for (; count < Pos; count++)
		dest[count] = src[count];

	dest[Pos] = '\0';
	return (dest);
}
