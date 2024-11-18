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

void	get_commands(t_pipex *pipex, char **argv)
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
}
