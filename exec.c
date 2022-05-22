#include "shell.h"

/**
 * check_builtin - Check for builtin command
 * @cmd: parsed Command
 * @er: statue of last Excute
 * Return: -1 Fail 0 Succes
 */
int check_builtin(char **cmd, int er)
{
    bul_t check[] = {
        {"cd", ch_dir},
		{"env", _env},
		{"help", _help},
		{"echo", echo_bul},
		{"history", _history},
		{NULL, NULL}
	};
	int i = 0;

	while ((check + i)->name)
	{
		if (strcmp(cmd[0], (check + i)->name) == 0)
		{
			return ((check + i)->func(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * check_cmd - Execute simple shell command (Fork,Wait,Execute)
 * @cmd: parsed command
 * @input: User Input
 * @c: shell execution time case of command not found
 * @argv: program name
 * Return: 1 - Null, -1 Wrong command, 0 - executed
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}
    pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (strncmp(*cmd, "./", 2) != 0 && strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}
		if (execve(*cmd, cmd, environ) == -1)
		{
			perror(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * signal_to_handel - Handle ^C
 * @sig: captured signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n$ ");
	}
}