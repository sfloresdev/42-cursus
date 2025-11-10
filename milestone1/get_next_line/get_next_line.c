/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:53:04 by seflores          #+#    #+#             */
/*   Updated: 2025/11/10 22:07:04 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_line(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	read_b;
	
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_b = 1;
	while (read_b != 0 && !ft_strchr(buffer, '\n'))
	{
		read_b = read(fd, tmp, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
		tmp[read_b] = '\0';
		buffer = ft_strjoin();			
	}
	return ();
}
static char	n_line(char *buffer)
{
	int		i;
	char	*left;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	left = ft_calloc(ft_strlen(buffer) - i, sizeof(char));
	i = 0;
	while (buffer[i])
	{
		left[i] = buffer[i];
		i++;	
	}
	if (buffer[i] == '\n')
		left[i] = '\n';
	i++;
	left[i] = '\0';
	return(left);
}



static char line(char *buffer)
{
	int		i;
	char 	*line;

	i = 0;
	if (!buffer[i])
		return(NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;	
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	
}