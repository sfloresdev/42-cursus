/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:17:45 by seflores          #+#    #+#             */
/*   Updated: 2025/10/18 21:33:41 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char dest1[20];
	char dest2[20];
	size_t ret_ft, ret_std;

	const char *src1 = "Hola Mundo";
	const char *src2 = "ABCDE";

	printf("=== CASOS DE PRUEBA ft_strlcpy ===\n\n");

	// 1. Copia normal, buffer suficiente
	memset(dest1, 'X', sizeof(dest1));
	memset(dest2, 'X', sizeof(dest2));
	ret_ft = ft_strlcpy(dest1, src1, sizeof(dest1));
	ret_std = strlcpy(dest2, src1, sizeof(dest2));
	printf("Test 1: size = 20\n");
	printf("ft_strlcpy -> \"%s\" (ret: %zu)\n", dest1, ret_ft);
	printf("strlcpy    -> \"%s\" (ret: %zu)\n\n", dest2, ret_std);

	// 2. Buffer justo
	memset(dest1, 'X', sizeof(dest1));
	memset(dest2, 'X', sizeof(dest2));
	ret_ft = ft_strlcpy(dest1, src1, 5);
	ret_std = strlcpy(dest2, src1, 5);
	printf("Test 2: size = 5 (corte)\n");
	printf("ft_strlcpy -> \"%s\" (ret: %zu)\n", dest1, ret_ft);
	printf("strlcpy    -> \"%s\" (ret: %zu)\n\n", dest2, ret_std);

	// 3. size = 0 → no copia nada, solo retorna longitud de src
	memset(dest1, 'X', sizeof(dest1));
	memset(dest2, 'X', sizeof(dest2));
	ret_ft = ft_strlcpy(dest1, src1, 0);
	ret_std = strlcpy(dest2, src1, 0);
	printf("Test 3: size = 0 (sin copia)\n");
	printf("ft_strlcpy -> \"%s\" (ret: %zu)\n", dest1, ret_ft);
	printf("strlcpy    -> \"%s\" (ret: %zu)\n\n", dest2, ret_std);

	// 4. src vacío
	memset(dest1, 'X', sizeof(dest1));
	memset(dest2, 'X', sizeof(dest2));
	ret_ft = ft_strlcpy(dest1, "", sizeof(dest1));
	ret_std = strlcpy(dest2, "", sizeof(dest2));
	printf("Test 4: src vacío\n");
	printf("ft_strlcpy -> \"%s\" (ret: %zu)\n", dest1, ret_ft);
	printf("strlcpy    -> \"%s\" (ret: %zu)\n\n", dest2, ret_std);

	// 5. size = 1 → solo debe escribir '\0'
	memset(dest1, 'X', sizeof(dest1));
	memset(dest2, 'X', sizeof(dest2));
	ret_ft = ft_strlcpy(dest1, src2, 1);
	ret_std = strlcpy(dest2, src2, 1);
	printf("Test 5: size = 1 (solo nulo)\n");
	printf("ft_strlcpy -> \"%s\" (ret: %zu)\n", dest1, ret_ft);
	printf("strlcpy    -> \"%s\" (ret: %zu)\n\n", dest2, ret_std);

	// 6. src largo, buffer pequeño
	memset(dest1, 'X', sizeof(dest1));
	memset(dest2, 'X', sizeof(dest2));
	ret_ft = ft_strlcpy(dest1, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	ret_std = strlcpy(dest2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 10);
	printf("Test 6: src más largo que dst\n");
	printf("ft_strlcpy -> \"%s\" (ret: %zu)\n", dest1, ret_ft);
	printf("strlcpy    -> \"%s\" (ret: %zu)\n\n", dest2, ret_std);

	return (0);
}*/