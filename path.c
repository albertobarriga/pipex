/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:41:17 by abarriga          #+#    #+#             */
/*   Updated: 2022/11/19 13:53:43 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*verify_path(char **all_paths, char *cmd);

static	char	**ft_free_mem(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (0);
}

char	*find_path(char **envp, char *cmd)
{
	int		i;
	char	**all_paths;
	char	*path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path = ft_strchr(envp[i], '/');
	all_paths = ft_split(path, ':');
	return (verify_path(all_paths, cmd));
}

static	char	*verify_path(char **all_paths, char *cmd)
{
	int		i;
	char	*upgrade_path;
	char	*full_path;

	i = -1;
	while (all_paths[++i])
	{
		upgrade_path = ft_strjoin(all_paths[i], "/");
		full_path = ft_strjoin(upgrade_path, cmd);
		free(upgrade_path);
		if (open(full_path, O_RDONLY) >= 0)
		{
			ft_free_mem(all_paths);
			return (full_path);
		}
		free(full_path);
	}
	ft_free_mem(all_paths);
	return (0);
}
