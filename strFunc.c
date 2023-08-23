#include "techsol.h"

/**
 * strConcat - function to concatenate three strings and allocate memory
 * @string1: first string
 * @string2: second string
 * @string3: third string
 * Return: pointer to the concatenated string
 */
char *strConcat(char *string1, char *string2, char *string3)
{
	int count = 0, count2 = 0, length1 = 0, length2 = 0, length3 = 0;
	char *output = NULL;

	/* Calculate the lengths of the input strings */
	length1 = stringLen(string1);
	length2 = stringLen(string2);
	length3 = stringLen(string3);

	/* Allocate memory for the concatenated string */
	output = ourCalloc((length1 + length2 + length3 + 1), 1);
	if (!output)
		return (NULL);


	/* Copy characters from the input strings to the concatenated string */
	for (count = 0; string1[count]; count++)
		output[count] = string1[count];
	count2 = count;

	for (count = 0; string2[count]; count++)
		output[count2 + count] = string2[count];
	count2 = count2 + count;

	for (count = 0; string3[count]; count++)
		output[count2 + count] = string3[count];
	count2 = count2 + count;

	output[count2] = '\0';

	return (output);
}

/**
 * putStr - function to print out strings
 * @string: string to write out
 */
void putStr(char *string)
{
	int count = 0;

	/* Print each character of the string */
	while (string[count])
	{
		_putchar(string[count]);
		count++;
	}
}

/**
 * stringDup - function to duplicate a string and allocate new memory
 * @string: pointer to the original string
 * Return: pointer to the duplicated string
 */
char *stringDup(char *string)
{
	char *after = NULL;
	int count = 0, count2 = 0;

	if (!string)
		return (NULL);

	/* Calculate the length of the input string */
	for (count2 = 0; string[count2] != '\0';)
		count2++;

	/* Allocate memory for the duplicated string */
	after = ourCalloc((sizeof(char) * count2 + 1), 1);

	if (!after)
		return (NULL);

	/* Copy characters from the original string to the duplicated string */
	for (count = 0; count < count2; count++)
		after[count] = string[count];
	after[count2] = string[count2];

	return (after);
}

/**
 * _putchar - function to print out a character to standard output
 * @ch: character to print
 * Return: success 1, error -1
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * stringLen - function to count characters in a string
 * @string: input string
 * Return: length of the string
 */
int stringLen(char *string)
{
	int strlen = 0, count = 0;

	/* Calculate the length of the string */
	while (string[count++])
		strlen++;

	return (strlen);
}

