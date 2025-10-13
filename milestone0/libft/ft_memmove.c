/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:10:42 by seflores          #+#    #+#             */
/*   Updated: 2025/10/13 20:43:17 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s || d >= s + n)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	} else
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return dest;
}


int	main(void)
{
	char	src1[] = "Hola mundo";
	char	dest1[20];

	ft_memmove(dest1, src1, 11);

	printf("Copia de la cadena de origen uno: %s\n", dest1);


	char str2[] = "123456789";
    	// Mover 5 bytes desde str2[0] hacia str2[2]
    	ft_memmove(str2 + 2, str2, 5);
    	printf("Solapamiento adelante: %s\n", str2);



	return (0);
}
