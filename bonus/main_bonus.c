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
	t_pipex_b	pipex;

	if (argc < 5)
		error_b(&pipex, 'A');
	init_struct(&pipex, argc, envp);
	init_fds_b(&pipex, argc, argv);
	get_commands_b(&pipex, argv);
	do_forks_b(&pipex);
	error_b(&pipex, '!');
	return (0);
}
