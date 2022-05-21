#include <shell.h>

/**
 * main - accepts arg
 * @ac: _attribute_
 * @av: Null terminated string pointer
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