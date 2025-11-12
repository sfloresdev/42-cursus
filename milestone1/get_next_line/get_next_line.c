/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:53:04 by seflores          #+#    #+#             */
/*   Updated: 2025/11/12 17:47:02 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_line(int fd, char *buffer)
{
	ssize_t	read_b;
	char	*str;
	
	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read_b = 1;
	while (read_b != 0 && !ft_strchr(buffer, '\n'))
	{
		read_b = read(fd, str, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		str[read_b] = '\0';
		buffer = ft_strjoin(buffer, str);			
	}
	free(str);
	return (buffer);
}
static char	left(char *buffer)
{
	char	*left;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	left = malloc((ft_strlen(buffer) - i) * sizeof(char));
	j = 0;
	while (buffer[++i])
	{
		left[j] = buffer[i];
		j++;
	}
	if (buffer[i] == '\n')
		left[j] = '\n';
	j++;
	left[j] = '\0';
	free(buffer);
	return(left);
}

static char *get_line(char *buffer)
{
	int		i;
	char 	*line;

	i = 0;
	if (!buffer[i])
		return(NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
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
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = left(buffer);
	return (line);	
}