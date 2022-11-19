/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:01:07 by abarriga          #+#    #+#             */
/*   Updated: 2022/11/18 14:28:54 by alberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pipex.h"

int main (int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (0);

	// Prueba
	printf("%s\n", find_path(envp, argv[2]));
	return (0);

	int status;
	int pp[2];

	if (pipe(pp) == -1)
		return (0);
	int pid = fork();
	
	if (pid == 0)
	{
		int fdin = open(argv[1], O_RDONLY);
		dup2(fdin, STDIN_FILENO);
		close(fdin);

		dup2(pp[1], STDOUT_FILENO);
		close(pp[1]);
		close(pp[0]);

		char *arguments[20] = {argv[1], NULL};
		execve(argv[1], arguments, envp);
		printf("ERROR: ha fallado execve\n");
		exit(-1);
	}

	close(pp[1]);

	int pid2 = fork();

	if (pid2 == 0)
	{
		dup2(pp[0], STDIN_FILENO);
		close(pp[0]);
		int fdout = open(argv[4], O_WRONLY | O_CREAT, 0644);
		dup2(fdout, STDOUT_FILENO);
		close(fdout);

		char *arguments[20] = {argv[3], NULL};
		execve(argv[3], arguments, envp);
		printf("ERROR: ha fallado execve\n");
		exit(-1);
	}

	close(pp[0]);
	waitpid(pid2, &status, 0);

	printf("Status: %d\n", WEXITSTATUS(status));
}
