/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:36:03 by seflores          #+#    #+#             */
/*   Updated: 2025/10/15 21:04:25 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char			a1[] = "Hola";
	char			b1[] = "Hola";
	char			a2[] = "Hola";
	char			b2[] = "Hoka";
	char			a3[] = "Hola";
	char			b3[] = "Hoku";
	unsigned char	x4[] = {1, 2, 3, 4, 5};
	unsigned char	y4[] = {1, 2, 4, 4, 5};
	char			a5[] = "ABCDE";
	char			b5[] = "XYZ";
	char			a6[] = "ABC";
	char			b6[] = "ABD";

	printf("Test 1 - Iguales:\n");
	printf("ft_memcmp: %d\n", ft_memcmp(a1, b1, 4));
	printf("memcmp:    %d\n\n", memcmp(a1, b1, 4));
	printf("Test 2 - Diferencia en un byte:\n");
	printf("ft_memcmp: %d\n", ft_memcmp(a2, b2, 4));
	printf("memcmp:    %d\n\n", memcmp(a2, b2, 4));
	// 3️⃣ Diferencia fuera del rango comparado
	printf("Test 3 - Diferencia fuera del rango:\n");
	printf("ft_memcmp: %d\n", ft_memcmp(a3, b3, 2)); // Solo compara 'H' y 'o'
	printf("memcmp:    %d\n\n", memcmp(a3, b3, 2));
	// 4️⃣ Comparando arrays binarios
	printf("Test 4 - Datos binarios:\n");
	printf("ft_memcmp: %d\n", ft_memcmp(x4, y4, 5));
	printf("memcmp:    %d\n\n", memcmp(x4, y4, 5));
	// 5️⃣ Comparando con n = 0 (no debe comparar nada)
	printf("Test 5 - n = 0:\n");
	printf("ft_memcmp: %d\n", ft_memcmp(a5, b5, 0));
	printf("memcmp:    %d\n\n", memcmp(a5, b5, 0));
	// 6️⃣ Diferencia con bytes mayores (para ver valor positivo/negativo)
	printf("Test 6 - Diferencia con valor mayor:\n");
	printf("ft_memcmp: %d\n", ft_memcmp(a6, b6, 3));
	printf("memcmp:    %d\n\n", memcmp(a6, b6, 3));
	return (0);
}*/
