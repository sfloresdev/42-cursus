/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:54:07 by seflores          #+#    #+#             */
/*   Updated: 2025/10/20 17:41:38 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	long	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if ((unsigned char) str[i] == ((unsigned char)c))
			return ((char *)str + i);
		i--;
	}
	if (!c)
		return ((char *)str);
	return (NULL);
}
