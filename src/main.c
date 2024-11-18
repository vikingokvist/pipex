/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:00:57 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/18 11:00:59 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pipex;

	if (argc != 5)
		error(&pipex, 'A');
	init_fds(&pipex, argv);
	get_commands(&pipex, argv);
	do_forks(&pipex, envp);
	error(&pipex, '!');
	return (0);
}
