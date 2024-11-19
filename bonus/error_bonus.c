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

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	close_fds_b(t_pipex_b *pipex)
{
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	if (pipex->fd[0] != -1)
		close(pipex->fd[0]);
	if (pipex->fd[1] != -1)
		close(pipex->fd[1]);
	close(0);
	close(1);
	close(2);
}

void	free_pipex_b(t_pipex_b *pipex)
{
	int	i;

	if (pipex->argv_cmd)
	{
		i = 0;
		while (pipex->argv_cmd[i])
		{
			if (pipex->argv_cmd[i])
				free(pipex->argv_cmd[i]);
			i++;
		}
		free(pipex->argv_cmd);
	}
	if (pipex->full_path)
	{
		i = 0;
		while (pipex->full_path[i])
		{
			if (pipex->full_path[i])
				free(pipex->full_path[i]);
			i++;
		}
		free(pipex->full_path);
	}
}

void	error_b(t_pipex_b *pipex, char c)
{
	free_pipex_b(pipex);
	close_fds_b(pipex);
	if (c != '!')
		perror("Error\n");
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
