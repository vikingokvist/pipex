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
	int		infile;
	int		outfile;
	char	**argv_cmd1;
	char	**argv_cmd2;
	char	*full_path1;
	char	*full_path2;
}	t_pipex;

void	get_commands(t_pipex *pipex, char **argv);
int		main(int argc, char **argv, char **envp);
void	do_forks(t_pipex *pipex, char **envp);
void	init_fds(t_pipex *pipex, char **argv);
void	error(t_pipex *pipex, char c);
void	free_pipex(t_pipex *pipex);
void	close_fds(t_pipex *pipex);


typedef struct s_pipex_b
{
	int		fd[2];
	int		infile;
	int		outfile;
	int		temp_fd;
	int		n_cmds;
	pid_t	pid;
	char	**argv_cmd;
	char	**full_path;
	char	**envp;
}	t_pipex_b;


void	init_struct(t_pipex_b *pipex, int argc, char **envp);
void	init_fds_b(t_pipex_b *pipex, int argc, char **argv);
void	swap_fds(t_pipex_b *pipex, int i);
void	get_commands_b(t_pipex_b *pipex, char **argv);
void	error_b(t_pipex_b *pipex, char c);
void	free_pipex_b(t_pipex_b *pipex);
void	close_fds_b(t_pipex_b *pipex);
void	do_forks_b(t_pipex_b *pipex);
void	free_array(char **array);


#endif
