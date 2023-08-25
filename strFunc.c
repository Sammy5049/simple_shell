#include "techsol.h"

/**
 * arrayFree - dynam allocated string free
 * @argc: item freed in num
 * @argv: malloc str array
 * Author: Techsol
 */

void arrayFree(int argc, char *argv[])
{
	int count;

	if (argv)
	{
		for (count = 0; count < argc; count++)
		{
			free(argv[count]);
		}
		free(argv);
	}
}
