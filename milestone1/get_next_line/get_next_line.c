/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:53:04 by seflores          #+#    #+#             */
/*   Updated: 2025/11/10 00:19:37 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	
}


static char *ft_read_line(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	read_b;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_b = 1;
	while (read_b != 0 && !ft_strchr(buffer, '\n'))
	{
		
	}
	return ();
}