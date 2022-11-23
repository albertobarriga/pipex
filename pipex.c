/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:01:07 by abarriga          #+#    #+#             */
/*   Updated: 2022/11/23 17:10:06 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pipex.h"

static char **split_arg1(char **argv)
{
	char	**all_arg;
	/* char	**all_arg2 */
	/* char	*cmd; */
	/* char	*flag; */
	/* int		i; */
	
	all_arg = ft_split(argv[2], ' ');
	/* all_arg2 = ft_split(argv[3], ' '); */
	/* cmd = all_arg[0]; */
	/* i = 1; */
	/* while (all_arg[i]) */
	/* { */
	/* 	flag[i - 1] = all_arg[i]; */
	/* 	i++; */
	/* } */
	return (all_arg);
	
}	

static char **split_arg2(char **argv)
{
	char	**all_arg2;
	/* char	**all_arg2 */
	/* char	*cmd; */
	/* char	*flag; */
	/* int		i; */
	
	all_arg2 = ft_split(argv[3], ' ');
	/* all_arg2 = ft_split(argv[3], ' '); */
	/* cmd = all_arg[0]; */
	/* i = 1; */
	/* while (all_arg[i]) */
	/* { */
	/* 	flag[i - 1] = all_arg[i]; */
	/* 	i++; */
	/* } */
	return (all_arg2);
	
}	



static void first_child(int *pp, char **argv, char **envp)
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
		
	/* char *arguments[20] = {path, NULL}; */
	/* Tengo qque controlar el numero de flags que me pongan para que no haya leaks, */
	
	/* char *arguments[20] = {path, all_arg, NULL}; */	
	/*execve(path, arguments, envp);*/
	execve(path, all_arg1, envp);

	printf("ERROR: ha fallado execve1\n");
	exit(-1);
}
static void second_child(int *pp, char **argv, char **envp)
{	
	char *path;
	char **all_arg2;

	dup2(pp[0], STDIN_FILENO);
	close(pp[0]);
	int fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
	all_arg2 = split_arg2(argv);
	path = find_path(envp, all_arg2[0]);

	/* char *arguments[20] = {path, NULL}; */
	/* execve(path, arguments, envp); */
	execve(path, all_arg2, envp);
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
