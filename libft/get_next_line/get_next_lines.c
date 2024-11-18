/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:35:31 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/01 12:35:35 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_next_lines(int fd)
{
	static char	*total_chars[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	total_chars[fd] = ft_read_line(fd, total_chars[fd]);
	if (total_chars[fd] == NULL)
		return (NULL);
	line = ft_save_line(total_chars[fd]);
	total_chars[fd] = ft_save_static(total_chars[fd]);
	return (line);
}
