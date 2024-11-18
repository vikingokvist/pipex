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

void	init_process(t_pipex *pipex, char **argv)
{
	pipex->fd1 = open(argv[1], O_RDONLY);
	if (pipex->fd1 == -1)
		error(pipex, 'O');
	pipex->fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->fd2 == -1)
		error(pipex, 'o');
	if (pipe(pipex->fd) == -1)
		error(pipex, 'P');
}
