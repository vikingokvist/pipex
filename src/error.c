/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:15:34 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/18 13:15:36 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	close_fds(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->infile);
	close(pipex->outfile);
}

void	free_pipex(t_pipex *pipex)
{
	int	i;

	if (pipex->fd[0] != -1)
		close(pipex->fd[0]);
	if (pipex->fd[1] != -1)
		close(pipex->fd[1]);
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	if (pipex->full_path1)
		free(pipex->full_path1);
	if (pipex->full_path1)
		free(pipex->full_path2);
	i = 0;
	while (pipex->argv_cmd1 && pipex->argv_cmd1[i])
		free(pipex->argv_cmd1[i++]);
	free(pipex->argv_cmd1);
	i = 0;
	while (pipex->argv_cmd2 && pipex->argv_cmd2[i])
		free(pipex->argv_cmd2[i++]);
	free(pipex->argv_cmd2);
	close(0);
	close(1);
	close(2);
}

void	error(t_pipex *pipex, char c)
{
	if (c != '!')
		perror("Error\n");
	free_pipex(pipex);
	if (c == 'A')
		perror("Wrong mount of Arguments.\n./pipex infile cmd1 cmd2 outfile");
	else if (c == 'O')
		perror("Opening infile.\n");
	else if (c == 'o')
		perror("Opening outfile.\n");
	else if (c == 'P')
		perror("Creating Pipe.\n");
	else if (c == 'F')
		perror("Creating Fork #1.\n");
	else if (c == 'f')
		perror("Creating Fork #2.\n");
	else if (c == 'p')
		perror("Processing Path.\n");
	else if (c == 'D')
		perror("Creating dup2.\n");
	else if (c == 'E')
		perror("Execve.\n");
	exit(1);
}
