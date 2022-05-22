#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <limits.h>

char *concat_all(char *name, char *sep, char *value);

void execute(char **argv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/** INPUT FUNC */
char prompt(void);
void signal_to_handel(int sig);
int *_getline(void);
int args(int ac _attribute_((unused)), char *av[]);

/** STRING FUNC */
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);

/** PARSER & EXTRACTOR */
int check_builtin(char **cmd, int er);
int check_cmd(char **tokens, char *line, int count, char **argv);

/**
 * struct builtin - pointer to function with corresponding buildin command
 * @name: pointer to char
 * @func: fun to excute when builtin is true
 */
typedef struct  builtin
{
	char *name;
	int (*func)(char **line, int er);
} bul_t;


extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;


char *_getenv(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *linkpath(char *path);
char *_which(char *filename, list_path *head);


void(*checkbuild(char **arv))(char **arv);
int _atoi(char *s);
void exitt(char **arv);
void env(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);

void freearv(char **arv);
void free_list(list_path *head);


#endif

/** environ var */

extern char **environ;

/** MACROS */

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

/** STRING FUNC */

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/** MEMORY  MANAGEMENT */

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);



/** Command parser and extractor */

int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *cmd);
void read_file(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);
void creat_envi(char **envi);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/** BUL FUNC #####*/

void hashtag_handle(char *buff);
int history(char *input);
int history_dis(char **cmd, int er);
int dis_env(char **cmd, int er);
int change_dir(char **cmd, int er);
int display_help(char **cmd, int er);
int echo_bul(char **cmd, int er);
void  exit_bul(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);

/** error handle and Printer */
void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);



#endif