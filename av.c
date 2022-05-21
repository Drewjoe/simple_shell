#include "shell.h"

/**
 * args - prints all arguments passed to it
 * @av: NULL terminated array of strings
 * @ac: number of items in av, unused arg
 * @_attribute_((unused): for arg ac
 * Return: Always 0
 */
int args(int ac _attribute_((unused)), char *av[])
{
	int i;

	for (i = 0; *av != NULL; i++)
	{
		printf("%s\n", *av);
		av++;
	}
	return (0);
}
