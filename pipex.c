/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:01:07 by abarriga          #+#    #+#             */
/*   Updated: 2022/11/23 18:45:52 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pipex.h"

static char	**split_arg1(char **argv)
{
	char	**all_arg1;

	all_arg1 = ft_split(argv[2], ' ');
	return (all_arg1);
}	

static char	**split_arg2(char **argv)
{
	char	**all_arg2;

	all_arg2 = ft_split(argv[3], ' ');
	return (all_arg2);
}	

static void	first_child(int *pp, char **argv, char **envp)
{
	int		fdin;
	char	*path;
	char	**all_arg1;

	fdin = open(argv[1], O_RDONLY);
	dup2(fdin, STDIN_FILENO);
	close(fdin);
	dup2(pp[1], STDOUT_FILENO);
	close(pp[1]);
	close(pp[0]);
	all_arg1 = split_arg1(argv);
	path = find_path(envp, all_arg1[0]);
	execve(path, all_arg1, envp);
	printf("ERROR: ha fallado execve1\n");
	exit(-1);
}

static void	second_child(int *pp, char **argv, char **envp)
{	
	char	*path;
	char	**all_arg2;
	int		fdout;

	dup2(pp[0], STDIN_FILENO);
	close(pp[0]);
	fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
	all_arg2 = split_arg2(argv);
	path = find_path(envp, all_arg2[0]);
	execve(path, all_arg2, envp);
	printf("ERROR: ha fallado execve2\n");
	exit(-1);
}

int	main(int argc, char **argv, char **envp)
{	
	int	status;
	int	pp[2];
	int	pid;
	int	pid2;

	if (argc != 5)
		return (0);
	if (pipe(pp) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		perror("Error");
	if (pid == 0)
		first_child(pp, argv, envp);
	close(pp[1]);
	pid2 = fork();
	if (pid2 == 0)
		second_child(pp, argv, envp);
	close(pp[0]);
	waitpid(pid2, &status, 0);
	printf("Status: %d\n", WEXITSTATUS(status));
}
