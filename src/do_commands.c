/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:27:33 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/18 13:27:34 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	do_forks(t_pipex *pipex, char **envp)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		error(pipex, 'F');
	if (pipex->pid1 == 0)
	{
		close(pipex->fd[0]);
		dup2(pipex->fd1, STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);
		close(pipex->fd1);
		close(pipex->fd[1]);
		execve(pipex->full_path1, pipex->argv_cmd1, envp);
	}
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		error(pipex, 'F');
	if (pipex->pid2 == 0)
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		dup2(pipex->fd2, STDOUT_FILENO);
		close(pipex->fd[0]);
		close(pipex->fd2);
		execve(pipex->full_path2, pipex->argv_cmd2, envp);
	}
}

void	do_commands(t_pipex *pipex, char **argv, char **envp)
{
	pipex->argv_cmd1 = ft_split(argv[2], ' ');
	if (!pipex->argv_cmd1)
		error(pipex, 'p');
	pipex->argv_cmd2 = ft_split(argv[3], ' ');
	if (!pipex->argv_cmd2)
		error(pipex, 'p');
	pipex->full_path1 = ft_strjoin("/usr/bin/", pipex->argv_cmd1[0]);
	if (!pipex->full_path1)
		error(pipex, 'p');
	pipex->full_path2 = ft_strjoin("/usr/bin/", pipex->argv_cmd2[0]);
	if (!pipex->full_path2)
		error(pipex, 'p');
	do_forks(pipex, envp);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}
