#include "shell.h"

/**
 * _getline - reads an entire line of string input
 * void: no arg passed
 * return: Number of char read
 */
int *_getline(void)
{
	char *s = NULL;
	size_t bufsize = 0;

	if (getline(&s, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
        {
			exit (EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit (EXIT_FAILURE);
		}
	}
	return(s);
}