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

static void	free_pipex(t_pipex *pipex)
{
	if (pipex->fd[0])
		close(pipex->fd[0]);
	if (pipex->fd[1])
		close(pipex->fd[1]);
}

void	error(t_pipex *pipex, char c)
{
	perror("Error\n");
	if (c == 'A')
		perror("Wrong mount of Arguments.\n Usage: ./pipex infile cmd1 cmd2 outfile");
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
	free_pipex(pipex);
	exit(1);	
}
