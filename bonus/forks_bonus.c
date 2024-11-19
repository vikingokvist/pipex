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

void	swap_fds(t_pipex_b *pipex, int i)
{
	char	**cmds;

	dup2(pipex->temp_fd, STDIN_FILENO);
	cmds = ft_split(pipex->argv_cmd[i], ' ');
	if (i < pipex->n_cmds - 1)
		dup2(pipex->fd[1], STDOUT_FILENO);
	else
		dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->temp_fd);
	execve(pipex->full_path[i], cmds, pipex->envp);
	free_array(cmds);
	error_b(pipex, 'E');
}

void	do_forks_b(t_pipex_b *pipex)
{
	int	i;

	i = 0;
	pipex->temp_fd = pipex->infile;
	while (i < pipex->n_cmds)
	{
		if (pipe(pipex->fd) == -1)
			error_b(pipex, 'P');
		pipex->pid = fork();
		if (pipex->pid == 0)
			swap_fds(pipex, i);
		close(pipex->fd[1]);
		if (pipex->temp_fd != pipex->infile)
			close(pipex->temp_fd);
		pipex->temp_fd = pipex->fd[0];
		i++;
	}
	// close(pipex->infile);
	// close(pipex->outfile);
	while (i-- > 0)
		waitpid(pipex->pid, NULL, 0);
}
