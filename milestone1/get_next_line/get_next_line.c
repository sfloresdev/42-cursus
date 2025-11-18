/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:53:04 by seflores          #+#    #+#             */
/*   Updated: 2025/11/18 19:32:06 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*init_buffer(char *buffer, char *str)
{
	char	*buffer;
	
	buffer = malloc(1);
	if (!buffer)
	{
		free(*str);
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
	read_b = 1;
	if (!buffer)
	{
		buffer = init_buffer(buffer, str);
		if (!buffer)
			return (NULL);
	}
	while (read_b != 0 && !ft_strchr(buffer, '\n'))
	{
		read_b = read(fd, str, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		str[read_b] = '\0';
		buffer = ft_strjoin(buffer, str);
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
		return (NULL);
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
	line = malloc((i + 2) * sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	i++;
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

	// Abrimos el archivo en modo lectura
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir archivo");
		return (1);
	}

	// Llamamos a get_next_line repetidamente hasta EOF
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Línea leída: %s", line);
		free(line); // Muy importante liberar la línea
	}

	close(fd);
	return (0);
}