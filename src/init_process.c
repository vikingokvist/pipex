/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:12:49 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/18 13:12:50 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_process(char **argv, t_pipex *pipex)
{
	pipex->fd[0] = open(argv[1], O_RDONLY);
	if (pipex->fd[0] == -1)
		error(pipex, 'O');
	pipex->fd[1] = open(argv[4], O_RDWR | O_WRONLY, 0644);
	if (pipex->fd[1] == -1)
		error(pipex, 'o');
	if (pipe(pipex->fd) == -1)
		error(pipex, 'P');
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		error(pipex, 'F');
	pipex->pid2 == fork();
	if (pipex->pid2 == -1)
		error(pipex, 'f');
}
