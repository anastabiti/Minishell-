#include <stdio.h>
#include <unistd.h>
int main()
{
    char *a;
    printf(" %lu \n", sysconf(_SC_ARG_MAX));
    return 0;
}