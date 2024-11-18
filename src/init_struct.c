/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:44:19 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/18 16:44:20 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_struct(t_pipex *pipex)
{
	pipex->fd1 = -1;
	pipex->fd1 = -1;
	pipex->fd[0] = -1;
	pipex->fd[1] = -1;
	pipex->pid1 = -1;
	pipex->pid2 = -1;
	pipex->argv_cmd1 = NULL;
	pipex->argv_cmd2 = NULL;
	pipex->full_path1 = NULL;
	pipex->full_path2 = NULL;
}
