/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:10:42 by seflores          #+#    #+#             */
/*   Updated: 2025/10/15 21:04:48 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d < s || d >= s + n)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	src1[] = "Hola mundo";
	char	dest1[20];
	char	str2[] = "123456789";

	ft_memmove(dest1, src1, 11);
	printf("Copia de la cadena de origen uno: %s\n", dest1);
	// Mover 5 bytes desde str2[0] hacia str2[2]
	ft_memmove(str2 + 2, str2, 5);
	printf("Solapamiento adelante: %s\n", str2);
	return (0);
}*/
