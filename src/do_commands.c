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

void	do_commands(char **argv, char **envp, t_pipex *pipex)
{
	char	*filepath;
	char	**argv_cmd;
	char	*full_path;

	filepath = "/usr/bin/";
	argv_cmd = ft_split(argv[1], ' ');
	if (!argv_cmd)
		error(pipex, 'p');
	full_path = ft_strjoin(filepath, argv_cmd[0]);
	if (!full_path)
		error(pipex, 'p');
	pipex->fd1 = dup2(pipex->fd[0], STDOUT_FILENO);
	if (pipex->fd1 == -1)
		error(pipex, 'D');
	execve(full_path, argv[1], envp);
	
	waitpid(pipex->pid1, NULL, 0);
	// waitpid(pipex->pid2, NULL, 0);
}