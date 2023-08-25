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
		if (strnCmp(environ[count], "PATH", 4) == 0)
			duplic = strDup(environ[count]);
	}
	/*free this return value if it's not NULL*/
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




/**
 * strnCmp - two str comp with number
 * @s1: str 1
 * @s2: second str
 * @n: bytes num compared
 * AUTHOR: Techsol
 * Return: 1 false, 0 true
 */
int strnCmp(char *s1, char *s2, size_t n)
{
	size_t count;
	if (s1 == NULL || s2 == NULL)
		return (1);
	for (count = 0; count < n; count++)
	{
		if (s1[count] != s2[count])
			return (1);
	}
	return (0);
}


/**
 * strDup - func to dup str
 * @string: str to duplicate
 * AUTHOR: Techsol
 * Return: duplicated str
 */
char *strDup(char *string)
{
	int count, strlen = 0;
	char *duplicate = NULL;
	strlen = strLen(string);
	duplicate = malloc(sizeof(char *) * strlen);
	if (duplicate == NULL)
		return (NULL);
	for (count = 0; string[count] != '\0'; count++)
		duplicate[count] = string[count];
	duplicate[count] = '\0';
	return (duplicate);
}
