/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:58:28 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/18 10:58:30 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_pipex
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		fd1;
	int		fd2;
	char	**argv_cmd1;
	char	**argv_cmd2;
	char	*full_path1;
	char	*full_path2;
}	t_pipex;

int		main(int argc, char **argv, char **envp);
void	error(t_pipex *pipex, char c);
void	free_pipex(t_pipex *pipex);
void	init_struct(t_pipex *pipex);
void	init_process(t_pipex *pipex, char **argv);
void	do_commands(t_pipex *pipex, char **argv, char **envp);

#endif
