#include <stdio.h>
#include <unistd.h>

/**
 * main - writes to stdout
 * void: no arg passed
 * Return: Aways 0
 */
int main(void)
{
	write(2, "ALX Task 0 file\n", 18);
	return (1);
}
