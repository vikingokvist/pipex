/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:19:55 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/19 11:19:56 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	do_forks(t_pipex *pipex, char **envp)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		error(pipex, 'F');
	if (pipex->pid1 == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
		close_fds(pipex);
		execve(pipex->full_path1, pipex->argv_cmd1, envp);
		error(pipex, 'E');
	}
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		error(pipex, 'F');
	if (pipex->pid2 == 0)
	{
		dup2(pipex->fd[0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close_fds(pipex);
		execve(pipex->full_path2, pipex->argv_cmd2, envp);
		error(pipex, 'E');
	}
	close_fds(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}
