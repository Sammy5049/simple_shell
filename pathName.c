#include "techsol.h"

/**
 * appendEndNode - append a new node to the end of pathListlp
 * @header: linked list pointer pointing to pointer
 * @string: string pointer for node data
 * Return: new element address
 */
pathListLp *appendEndNode(pathListLp **header, char *string)
{
	pathListLp *after = NULL, *tmpFile = NULL;

	/* Allocate memory for the new node */
	after = ourCalloc((sizeof(pathListLp)), 1);

	if (!after || !string)
		return (NULL);

	/* Store the provided string in the new node */
	after->directory = string;
	after->ptr = '\0';

	/* If the list is empty, make the new node the header */
	if (!*header)
		*header = after;
	else
	{
		tmpFile = *header;

		/* Traverse to the end of the list and attach the new node */
		while (tmpFile->ptr)
			tmpFile = tmpFile->ptr;
		tmpFile->ptr = after;
	}
	return (*header);
}

/**
 * listFreed - function to free a linked list
 * @header: linked list head
 */
void listFreed(pathListLp *header)
{
	pathListLp *real;

	if (!header)
		return;

	/* Free each node in the linked list */
	while (header->ptr)
	{
		real = header->ptr;
		free(header);
		header = real;
	}
	free(header);
}

/**
 * getEnviron - function to get the value of an environment variable
 * @globName: global variable name
 * Return: the value of the environment variable
 */
char *getEnviron(const char *globName)
{
	char *strVal = NULL;
	int count, count2 = 0;

	if (!globName)
		return (NULL);

	/* Search for the environment variable by name */
	for (count = 0; environ[count]; count++)
	{
		if (globName[count2] == environ[count][count2])
		{
			while (globName[count2])
			{
				if (globName[count2] != environ[count][count2])
					break;
				count2++;
			}
			if (globName[count2] == '\0')
			{
				/* Extract and return the value of the environment variable */
				strVal = (environ[count] + count2 + 1);
				return (strVal);
			}
		}
	}
	return (0);
}

/**
 * wchPath - function to find the path of a named file
 * @cmdName: name of the command to check
 * @header: linked list header for file directories
 * Return: the path name or NULL when not found
 */
char *wchPath(char *cmdName, pathListLp *header)
{
	char *str = NULL;
	struct stat strucSt;

	pathListLp *tmpFile = header;

	/* Search for the command name in each directory in the linked list */
	while (tmpFile)
	{
		/* Concatenate the directory path with the command name */
		str = strConcat(tmpFile->directory, "/", cmdName);
		if (stat(str, &strucSt) == 0)
			return (str); /* Return the path if the command is found */
		free(str);
		tmpFile = tmpFile->ptr;
	}

	return (NULL); /*  Return NULL if the command is not found */
}

/**
 * pathDirLink - function to create a linked list of path directories
 * @strPath: path string to be split
 * Return: linked list of path directories
 */
pathListLp *pathDirLink(char *strPath)
{
	char *pathTok = NULL;
	char *pathCopy = stringDup(strPath);
	pathListLp *header = '\0';

	/* Tokenize the path string using ':' delimiter */
	pathTok = strtok(pathCopy, ":");

	/* Create a linked list by appending each path directory */
	while (pathTok)
	{
		header = appendEndNode(&header, pathTok);
		pathTok = strtok(NULL, ":");
	}

	return (header);
}

