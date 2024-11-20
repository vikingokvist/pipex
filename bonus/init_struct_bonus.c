/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:29:02 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/19 15:29:03 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_struct(t_pipex_b *pipex, int argc, char **envp)
{
	pipex->n_cmds = argc - pipex->n;
	pipex->argv_cmd = malloc(sizeof(char *) * pipex->n_cmds);
	if (!pipex->argv_cmd)
		error_b(pipex, '!');
	pipex->full_path = malloc(sizeof(char *) * pipex->n_cmds);
	if (!pipex->full_path)
		error_b(pipex, '!');
	pipex->envp = envp;
}
