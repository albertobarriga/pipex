#include "pipex.h"

void  *find_path ( char **envp, char *cmd)
{
	int	i;
	char **all_paths;
	char *path;
	char *upgrade_path;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path = ft_strchr(envp[i], '/');
	all_paths = ft_split(envp[i], ':');

	i = 0;
	while (all_paths[i])
	{
		upgrade_path = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(upgrade_path, cmd);
	}
}

int main (int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		find_path(envp, argv[2]);
	}
	/* return (0); */
}
