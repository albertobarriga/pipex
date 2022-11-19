/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:01:07 by abarriga          #+#    #+#             */
/*   Updated: 2022/11/19 17:01:37 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pipex.h"

static char *split_arg1(char *argv,)
{
	char	**all_arg;
	char	*cmd;
	char	*flag;
	int		i;
	
	all_arg = ft_split(argv[2], ' ');
	cmd = all_arg[0];
	i = 1;
	while (all_arg[i])
	{
		flag[i - 1] = all_arg[i];
		i++;
	}
	
}	

static void first_child(int *pp, char **argv, char **envp)
{
	int fdin;
	char *path;
	
	fdin = open(argv[1], O_RDONLY);
	dup2(fdin, STDIN_FILENO);
	close(fdin);

	dup2(pp[1], STDOUT_FILENO);
	close(pp[1]);
	close(pp[0]);

	path = find_path(envp, argv[2]);

	char *arguments[20] = {path, NULL};
	execve(path, arguments, envp);
	printf("ERROR: ha fallado execve1\n");
	exit(-1);
}
static void second_child(int *pp, char **argv, char **envp)
{	
	char *path;

	dup2(pp[0], STDIN_FILENO);
	close(pp[0]);
	int fdout = open(argv[4], O_WRONLY | O_CREAT, 0644);
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
	path = find_path(envp, argv[3]);

	char *arguments[20] = {path, NULL};
	execve(path, arguments, envp);
	printf("ERROR: ha fallado execve2\n");
	exit(-1);
}

int main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (0);

	// Prueba
	/* printf("%s\n", find_path(envp, argv[2])); */
	/* printf("%s\n", find_path(envp, argv[3])); */

	/* return (0); */

	int status;
	int pp[2];

	if (pipe(pp) == -1)
		return (0);


	int pid;
	pid = fork();

	if (pid == -1)
		perror("Error");
	
	if (pid == 0)
	{
		first_child(pp, argv, envp);

		/* int fdin = open(argv[1], O_RDONLY); */
		/* dup2(fdin, STDIN_FILENO); */
		/* close(fdin); */

		/* dup2(pp[1], STDOUT_FILENO); */
		/* close(pp[1]); */
		/* close(pp[0]); */

		/* char *arguments[20] = {argv[1], NULL}; */
		/* execve(argv[1], arguments, envp); */
		/* printf("ERROR: ha fallado execve\n"); */
		/* exit(-1); */
	}
	close(pp[1]);

	int pid2;
	pid2 = fork();

	if (pid2 == 0)
	{
		second_child(pp, argv, envp);

		/* dup2(pp[0], STDIN_FILENO); */
		/* close(pp[0]); */
		/* int fdout = open(argv[4], O_WRONLY | O_CREAT, 0644); */
		/* dup2(fdout, STDOUT_FILENO); */
		/* close(fdout); */

		/* char *arguments[20] = {argv[3], NULL}; */
		/* execve(argv[3], arguments, envp); */
		/* printf("ERROR: ha fallado execve\n"); */
		/* exit(-1); */
	}

	close(pp[0]);
	waitpid(pid2, &status, 0);

	printf("Status: %d\n", WEXITSTATUS(status));
}
