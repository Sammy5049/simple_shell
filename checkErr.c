#include "techsol.h"
/**
 * handleError - Pprint err messge
 * @program: file name
 * @counter: cmd
 * @cmdcnt: entered cmd
 * Author: techsol
 *
 */

void handleError(char *program, int counter, char *cmdcnt)
{
	putstr(program);
	putstr(": ");
	_putchar(counter);
	putstr(": ");
	putstr(cmdcnt);
	putstr(": not found\n");
}

/**
 * putstr - prints string
 * @string: String printed
 * Author: techsol
 *
 */

void putstr(char *string)
{
	while (*string != '\0')
	{
		_putchar(*string);
		string++;
	}
}

/**
 * _putchar - Prints a character to standard error
 * @c: Character to be printed
 * Author: David Obodo (Cohort 16 - ALX)
 * Return: An integer
 */

int _putchar(char c)
{
	return (write(2, &c, 1));
}
