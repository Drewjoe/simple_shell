/**
 * Write a function that splits a string and returns an array of each word of the string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **splstr(char *str, const char *delim);

char **splstr(char *str, const char *delim)
{
    int i, n;
    char **array;
    char *token;
    char *c;
    
    c = malloc(strlen(str) + 1);
    
    if (c == NULL)
    {
        perror(getenv("_"));
        return(NULL);
    }
    i = 0;
    while (str[i])
    {
        c[i] = str[i];
        i++;
    }
    c[i] = '\0';
    token = strtok(c, delim);
    array = malloc((sizeof(char *) * 2)); // we are allocating memory to this array by the size of character * by 2; 8bytes of allocated memory
    array[0] = strdup(token);
    
    i = 1;
    n = 3;
    while(token)
    {
        token = strtok(NULL, delim);
        array = realloc(array, (sizeof(char *) * n));
        array[i] = strdup(token);
        i++;
        n++;
    }
    free(c);
    return(array);
}