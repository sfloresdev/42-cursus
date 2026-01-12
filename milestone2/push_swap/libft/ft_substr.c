/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:21:04 by seflores          #+#    #+#             */
/*   Updated: 2025/10/18 21:34:11 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		string = malloc(1);
		if (!string)
			return (NULL);
		string[0] = '\0';
		return (string);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	string = malloc(len + 1);
	if (!string)
		return (NULL);
	ft_strlcpy(string, (s + start), len + 1);
	return (string);
}
