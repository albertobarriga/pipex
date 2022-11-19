#include "pipex.h"

char  *find_path ( char **envp, char *cmd)
{
	int	i;
	char **all_paths;
	char *path;
	char *upgrade_path;
	char *full_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path = ft_strchr(envp[i], '/');
	all_paths = ft_split(path, ':');

	i = -1;
	while (all_paths[++i])
	{
		upgrade_path = ft_strjoin(all_paths[i], "/");
		full_path = ft_strjoin(upgrade_path, cmd);
		free(upgrade_path);
		if (open(full_path, O_RDONLY) >= 0)
		{
			free(all_paths);
			return (full_path);
		}
		free(full_path);
	}
	return (0);
}

static	char	**ft_free_mem(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs);
	return (0);
}


