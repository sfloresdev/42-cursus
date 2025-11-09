/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:53:34 by seflores          #+#    #+#             */
/*   Updated: 2025/11/10 00:10:09 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str != (char) c)
	{
		if (!(*str))
			return (NULL);
		str++;
	}
	return ((char *)str);
}