

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
		if(ft_strnstr(env[x], "SHLVL", 5))
		{
			char **split = ft_split(env[x], '=');
			int nb = ft_atoi(split[1]);
			char *joined = ft_strjoin("SHLVL=",  ft_itoa(nb + 1) );
			new[x] = joined;
			x++;
		}
		new[x] = env[x];
		
		x++;
	}
	new[x] = NULL;
	envp->environment = new;
}