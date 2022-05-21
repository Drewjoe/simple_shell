#include <shell.h>

/**
 * args - prints all args passed to it
 * @av: NULL terminated array of strings
 * @ac: number of items in av, unused arg
 * @return: Number of argument passed
 */
int args(int ac _attribute_((unused)), char *av[])
{
    int i;

    for (i = 0; *av != NULL; i++)
    {
        printf("%s\n", *av);
        av++;
    }
    return(0);
}