#include "shell.h"

/**
 * prompt - Displays shell prompt
 * void: no arg is passed
 * return: char
 */
char prompt(void)
{
    char *s = "$ ";
    char *x;
    int i;

    printf("%s", s);
    x = _getline();
    printf("%s", x);
    for (i = 0; i < x[i]; i++)
    {
        printf("%s", s);
        x = _getline();
        printf("%s", x);
    }
    return (0);
}