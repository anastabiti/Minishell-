
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int	main(int ac, char **av)
{
    
	///home/anas/hadahowalkhar/last2206/.minishell it must not work
	if (fork() == 0)
	{
		if (av[1][0] == '.' && av[1][1] == '/')
		{
			char *cmd[3] = {av[1], NULL};
			execve(av[1], cmd, NULL);
			printf("failed");
		}
		else if (av[1][0] == '/')
		{
			char *cmd[3] = {av[1], NULL};
			execve(av[1], cmd, NULL);
		}
		exit(1);
	}
	else
		wait(NULL);
}