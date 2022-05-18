#include <stdio.h>
#include <unistd.h>

int main(void)
{
    write(2, "ALX Task 0 file", 15);
    return 1;
}