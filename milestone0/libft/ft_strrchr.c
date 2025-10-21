/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:54:07 by seflores          #+#    #+#             */
/*   Updated: 2025/10/21 18:25:13 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;
	char	*ptr;

	last = NULL;
	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == (char)c)
			last = ptr;
		ptr++;
	}
	if ((char)c == '\0')
		return (ptr);
	return (last);
}
/*long	i;

i = ft_strlen(str);
while (i >= 0)
{
	if ((unsigned char) str[i] == ((unsigned char)c))
		return ((char *)str + i);
	i--;
}
if (!c)
	return ((char *)str);
return (NULL);*/