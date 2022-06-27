

#include "../minishell.h"
#include "parse.h"

void	ft_copy_1st_env(struct s_envp *envp, char **env)
{
	char **new;

	int len;

	int x = 0;
	len = 0;
	while (env[len])
	{
		len++;
	}
	envp->envpitems = len;
	new = malloc(sizeof(char **) * (len + 1));

	while (x < len)
	{
		new[x] = env[x];

		x++;
	}
	new[x] = NULL;
	envp->environment = new;
}