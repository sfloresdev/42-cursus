/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:35:59 by seflores          #+#    #+#             */
/*   Updated: 2025/10/18 21:33:59 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	s2_len;

	s2_len = ft_strlen(s2);
	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (i < len && s1[i])
	{
		if (i + s2_len <= len && ft_strncmp(s1 + i, s2, s2_len) == 0)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
