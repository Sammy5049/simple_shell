#include "techsol.h"



/**
 * pathName - get pathname and dup
 * Author: Techsol
 * Return: path var str
 */

char *pathName(void)
{
	int count;
	char *duplic = NULL;

	for (count = 0; environ[count] != NULL; count++)
	{
		if (strncmp(environ[count], "PATH", 4) == 0)
			duplic = strdup(environ[count]);
	}
	/*Make sure to free this return value if it's not NULL*/
	return (duplic);
}




/**
 * handleTok - funct to tok str and allocate mem
 * @str: str buf from input
 * Return: str double ptr
 * Description: TECHSOL
 */

char **handleTok(char *str)
{
	int position = 0;
	char *str_delim = " \n", *tokenized = NULL, **strToken = NULL;

	strToken = malloc(sizeof(char *) * 25);
	if (strToken == NULL)
		return (NULL);

	tokenized = strtok(str, str_delim);

	while (tokenized != NULL)
	{
		strToken[position] = tokenized;
		tokenized = strtok(NULL, str_delim);
		position++;
	}

	strToken[position] = NULL;
	return (strToken);
}
