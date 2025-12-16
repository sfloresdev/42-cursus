/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:53:04 by seflores          #+#    #+#             */
/*   Updated: 2025/12/16 16:52:09 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*init_buffer(char *str)
{
	char	*buffer;

	buffer = malloc(1);
	if (!buffer)
	{
		free(str);
		return (NULL);
	}
	buffer[0] = '\0';
	return (buffer);
}

static char	*read_line(int fd, char *buffer)
{
	ssize_t	read_b;
	char	*str;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		buffer = init_buffer(str);
		if (!buffer)
			return (free(str), NULL);
	}
	read_b = 1;
	while (read_b != 0 && !ft_strchr(buffer, '\n'))
	{
		read_b = read(fd, str, BUFFER_SIZE);
		if (read_b == -1)
			return (free(str), free(buffer), NULL);
		str[read_b] = '\0';
		buffer = ft_strjoin(buffer, str);
		if (!buffer)
			return (free(str), NULL);
	}
	free(str);
	return (buffer);
}

static char	*left(char *buffer)
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
	i++;
	left = malloc(((ft_strlen(buffer) - i) * sizeof(char)) + 1);
	if (!left)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	while (buffer[i])
		left[j++] = buffer[i++];
	left[j] = '\0';
	free(buffer);
	return (left);
}

static char	*get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + (buffer[i] == '\n') + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
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

int	main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir archivo");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Línea leída: %s", line);
		free(line);
	}

	close(fd);
	return (0);
}