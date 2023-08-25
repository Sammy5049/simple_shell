#include "techsol.h"

/**
 * ourUnsetEnv - function to delete an environment variable
 * @funcDet: Struct holding argument prototype
 * @variable: variable name
 * Return: 1 when removed, and 0 when failed to remove
 */
int ourUnsetEnv(getDetail *funcDet, char *variable)
{
	char **envVariable = funcDet->envVariable, *ptr, **newEnvVar;
	size_t count = 0, newEnvVariableSize = 0, positionBefore;

	if (!envVariable || !variable)
		return (0);
	/* Iterate existing environment variables to remove specified one */
	for (positionBefore = 0; envVariable[positionBefore]; positionBefore++)
	{
		ptr = strstr(envVariable[positionBefore], variable);
		if (ptr != envVariable[positionBefore])
		{
			/* not the variable to remove, copy to new environment variable list */
			envVariable[newEnvVariableSize] = envVariable[positionBefore];
			newEnvVariableSize++;
		}
		else
		{
			/* Free memory for the variable removed and mark change */
			free(envVariable[positionBefore]);
			funcDet->change_env = 1;
		}
	}

	envVariable[newEnvVariableSize] = NULL;
	if (newEnvVariableSize != count)
	{
		/* Reallocate memory if the new size is different from the old */
		newEnvVar = realloc(envVariable, sizeof(char *) * (newEnvVariableSize + 1));
		if (!newEnvVar)
			return (0);
		funcDet->envVariable = newEnvVar;
	}

	return (funcDet->change_env);
}

/**
 * ourSetEnv - function to modify or initialize an environment variable
 * @funcDet: Struct to hold argument prototype
 * @variable: string variable
 * @variableVal: variable value as a string
 * Return: 0 on success
 */
int ourSetEnv(getDetail *funcDet, char *variable, char *variableVal)
{
	char *buffer = NULL, *ptr, **envVariable = funcDet->envVariable, **newEnvVar;
	int position;

	if (!variable || !variableVal)
		return (0);
	/* Prepare the new environment variable in the format "variable=value" */
	buffer = malloc(stringLen(variable) + stringLen(variableVal) + 2);
	if (!buffer)
		return (1);
	strcpy(buffer, variable);
	strcat(buffer, "=");
	strcat(buffer, variableVal);
	position = 0;
	while (envVariable[position])
	{
		ptr = strstr(envVariable[position], variable);
		if (ptr == envVariable[position])
		{
			/* If the variable already exists, replace its value and mark change */
			free(envVariable[position]);
			envVariable[position] = buffer;
			funcDet->change_env = 1;
			return (0);
		}
		position++;
	}
	/* If the variable doesn't exist, add it to the environment variable list */
	newEnvVar = realloc(envVariable, sizeof(char *) * (position + 2));
	if (!newEnvVar)
	{
		free(buffer);
		return (1);
	}
	newEnvVar[position] = buffer;
	newEnvVar[position + 1] = NULL;
	funcDet->envVariable = newEnvVar;
	funcDet->change_env = 1;

	return (0);
}

/**
 * setenvCase - function to modify or initialize an environment variable
 * @funcDet: Struct to hold argument prototype
 * Return: 0 on success
 */
int setenvCase(getDetail *funcDet)
{
	if (funcDet->argc != 3)
	{
		putStr("Number of Arguments not correct\n");
		return (1);
	}
	if (ourSetEnv(funcDet, funcDet->argv[1], funcDet->argv[2]))
		return (0);
	return (1);
}

/**
 * unsetenvCase - function to eliminate environment variables
 * @funcDet: Struct to hold argument prototype
 * Return: 0 on success
 */
int unsetenvCase(getDetail *funcDet)
{
	int count;

	if (funcDet->argc == 1)
	{
		putStr("Arguments not enough.\n");
		return (1);
	}
	for (count = 1; count < funcDet->argc; count++)
		ourUnsetEnv(funcDet, funcDet->argv[count]);

	return (0);
}

