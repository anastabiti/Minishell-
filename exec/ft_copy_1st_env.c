

#include "../minishell.h"
#include "parse.h"

char	**ft_copy_1st_env(char **env)
{
	char **new;

	int len;

	int x = 0;
	len = 0;
	while (env[len])
	{
        	// printf("%s\n", env[len]);

		len++;
		
	}
    // printf("%d  len\n", len);
    	new = malloc(sizeof(char **) * (len + 1));
  
   
   
        while(x < len)
        {

                    new[x] = env[x];

            x++;
        }
        // new[x] = NULL;
        return new;
}