

#include "../minishell.h"

char	**join_name_and_value(struct s_envp *envp, t_cmdl *cmd)
{
	int		i;
	char	**joined;
	char	*tmp1;

	i = 0;
	joined = malloc(sizeof(char **) * 101);
	i = 0;
	while (i < envp->envpitems)
	{
		tmp1 = ft_strjoin(envp->name[i], "=\"");
		joined[i] = ft_strjoin(tmp1, envp->value[i]);
		i++;
	}
	return (joined);
}

char	**ft_sort_env(struct s_envp *envp, t_cmdl *cmd)
{
	int		i;
	int		j;
	char	*tmp;
	char	**joined;

	joined = join_name_and_value(envp, cmd);
	i = 0;
	while (i < envp->envpitems)
	{
		j = i + 1;
		while (j < envp->envpitems)
		{
			if (strcmp(envp->name[i], envp->name[j]) > 0)
			{
				tmp = joined[i];
				joined[i] = joined[j];
				joined[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (joined);
}

int	ft_export_1(struct s_envp *envp, t_cmdl *cmd)
{
	int		i;
	char	**new;
	char	*clone;
	int		x;
	char	**joined;

	x = 0;
	i = 0;
	joined = ft_sort_env(envp, cmd);
	i = 0;
	while (i < envp->envpitems)
	{
		printf("declare -x %s\"\n", joined[i]);
		i++;
	}
	i = 0;
	while (i < envp->envpitems)
	{
		free(joined[i]);
		i++;
	}
	free(joined);
	return (0);
}

int	check_name_is_valid(char **split, int i, t_cmdl *cmd)
{
	if (ft_is_alpha_mod(split[0][0]) == 0)
	{
		printf("Minishell: export: `%s': not a valid identifier\n",
				cmd[0].args[i]);
		return (1);
	}
	return (0);
}