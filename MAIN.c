#include <stdio.h> //stdio means standard input and output
#include <stdlib.h>

// ppid is the parent process
//pid is a child process that runs on the system
int main(void){
    pid_t my_pid;
    my_pid = getpid(); 
    printf("%u\n", my_pid);
    return (0);
}