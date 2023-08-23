#include "techsol.h"

/**
 * ourGetlineFunc - function to get input from terminal
 * @strptr: pointer to buffer to store the read string
 * @number: pointer to size of the buffer
 * @termread: stream from stdio (terminal)
 * Return: number of characters read
 */
ssize_t ourGetlineFunc(char **strptr, size_t *number, FILE *termread)
{
	size_t bufSize, location = 0;
	int ch;
	char *ptAfter;

	if (strptr == NULL || termread == NULL)/* Check if input pointers are valid */
		return (-1);
	bufSize = (number && *number) ? *number : 128;
	if (*strptr == NULL)/* Allocate memory for the buffer created */
	{
		*strptr = (char *)malloc(bufSize);
		if (*strptr == NULL)
			return (-1);
	}
	while (1)
	{
		ch = fgetc(termread);/* Read characters from the terminal */
		if (ch == EOF || ch == '\n')
		{
			(*strptr)[location] = '\0';
			if (location == 0 && ch == EOF)
				return (-1);
			else
				return (location + 1);
		}
		(*strptr)[location++] = (char)ch;/* Store read character in buffer */
		if (location >= bufSize - 1)
		{
			bufSize *= 2;/* Double the buffer size and reallocate memory if needed */
			ptAfter = (char *)realloc(*strptr, bufSize);
			if (ptAfter == NULL)
			{
				free(*strptr);
				*strptr = NULL;
				return (-1);
			}
			*strptr = ptAfter;
		}
	}
	return (-1);
}

