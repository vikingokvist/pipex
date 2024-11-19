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

void	get_commands_b(t_pipex_b *pipex, char **argv)
{
	int		i;
	char	**temp1;

	i = 0;
	while (i < pipex->n_cmds)
	{
		temp1 = ft_split(argv[i + 2], ' ');
		if (!temp1)
			error_b(pipex, 'p');
		pipex->argv_cmd[i] = argv[i + 2];
		if (!pipex->argv_cmd[i])
			error_b(pipex, 'p');
		pipex->full_path[i] = ft_strjoin("/usr/bin/", temp1[0]);
		if (!pipex->full_path[i])
			error_b(pipex, 'p');
		free_array(temp1);
		i++;
	}
	
}
