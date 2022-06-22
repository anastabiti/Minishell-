
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int	main(void)
{
	///home/anas/hadahowalkhar/last2206/.minishell it must not work
	if (fork() == 0)
	{
		char *cmd[11] = {"minishell", NULL};
		execve("/home/anas/hadahowalkhar/last2206/minishell", cmd, NULL);
		printf("failed");
	}
	else
		wait(NULL);
}