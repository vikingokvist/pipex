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

static void	here_doc(t_pipex_b *pipex, char **argv)
{
	int		here_doc_fd;
	char	*buf;

	here_doc_fd = open(".here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (here_doc_fd == -1)
		error_b(pipex, 'o');
	while (1)
	{
		buf = get_next_line(0);
		if (!ft_strncmp(buf, argv[2], ft_strlen(argv[2])))
		{
			free(buf);
			break ;
		}
		write(here_doc_fd, buf, ft_strlen(buf));
		free(buf);
	}
	close(here_doc_fd);
	pipex->infile = open(".here_doc", O_RDONLY);
	if (pipex->infile == -1)
		error_b(pipex, 'o');
}

void	init_fds_b(t_pipex_b *pipex, int argc, char **argv)
{
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile == -1)
		error_b(pipex, 'o');
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		here_doc(pipex, argv);
		pipex->n = 4;
	}
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile == -1)
			error_b(pipex, 'O');
		pipex->n = 3;
	}
}
