/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:54:07 by seflores          #+#    #+#             */
/*   Updated: 2025/10/22 18:47:59 by seflores         ###   ########.fr       */
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
