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

void	swap_fds(t_pipex_b *pipex, int in_fd, int j)
{
	char	**args;

	dup2(in_fd, STDIN_FILENO);
	args = ft_split(pipex->argv_cmd[j], ' ');
	if (j < pipex->n_cmds - 1)
		dup2(pipex->fd[1], STDOUT_FILENO);
	else
		dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->fd[1]);
	close(pipex->fd[0]);
	close(in_fd);
	execve(pipex->full_path[j], args, pipex->envp);
	free_array(args);
}

void	do_forks_b(t_pipex_b *pipex)
{
	int	j;
	int	in_fd;

	j = 0;
	in_fd = pipex->infile;
	while (j < pipex->n_cmds)
	{
		if (pipe(pipex->fd) == -1)
			error_b(pipex, 'P');
		pipex->pid = fork();
		if (pipex->pid == 0)
			swap_fds(pipex, in_fd, j);
		close(pipex->fd[1]);
		if (in_fd != pipex->infile)
			close(in_fd);
		in_fd = pipex->fd[0];
		j++;
	}
	close(pipex->infile);
	close(pipex->outfile);
	while (j-- > 0)
		waitpid(pipex->pid, NULL, 0);
}
