/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:53:37 by seflores          #+#    #+#             */
/*   Updated: 2025/11/12 18:01:56 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strchr(const char *str, int c);
void	ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif