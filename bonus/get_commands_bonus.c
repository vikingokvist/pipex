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

void	get_commands_b(t_pipex_b *pipex, char **argv, int i)
{
	int		j;
	char	**temp1;

	j = i - 2;
	temp1 = ft_split(argv[i], ' ');
	if (!temp1)
		error_b(pipex, 'p');
	pipex->argv_cmd[j] = ft_strdup(argv[i]);
	if (!pipex->argv_cmd[j])
		error_b(pipex, 'p');
	pipex->full_path[j] = ft_strjoin("/usr/bin/", temp1[0]);
	if (!pipex->full_path[j])
		error_b(pipex, 'p');
	free_array(temp1);
}
