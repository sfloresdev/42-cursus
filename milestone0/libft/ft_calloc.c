/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:25:34 by seflores          #+#    #+#             */
/*   Updated: 2025/10/15 21:01:59 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total = nmemb * size;
	ptr = malloc(total);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, total);
		return (ptr);
	}
	return (NULL);
}
/*
int	main(void)
{
	int i;
	int *ptr;

	printf("=== PRUEBAS ft_calloc ===\n\n");

	// Test 1: Reserva normal
	ptr = ft_calloc(5, sizeof(int));
	if (ptr)
	{
		printf("Test 1 OK: memoria asignada.\n");
		for (i = 0; i < 5; i++)
		{
			if (ptr[i] != 0)
				printf("Error: ptr[%d] no es 0\n", i);
		}
		free(ptr);
	}
	else
		printf("Test 1 FAIL: puntero NULL\n");

	// Test 2: nmemb = 0
	ptr = ft_calloc(0, sizeof(int));
	printf("Test 2: nmemb = 0, puntero = %p\n", (void *)ptr);
	free(ptr); // seguro incluso si es NULL

	// Test 3: size = 0
	ptr = ft_calloc(5, 0);
	printf("Test 3: size = 0, puntero = %p\n", (void *)ptr);
	free(ptr);

	// Test 4: Reserva grande
	size_t n = 1000;
	ptr = ft_calloc(n, sizeof(int));
	if (ptr)
	{
		int ok = 1;
		for (i = 0; i < 1000; i++)
		{
			if (ptr[i] != 0)
			{
				ok = 0;
				printf("Error: ptr[%d] no es 0\n", i);
				break ;
			}
		}
		printf("Test 4 %s\n", ok ? "OK: memoria inicializada a 0" : "FAIL");
		free(ptr);
	}
	else
		printf("Test 4 FAIL: memoria no asignada\n");

	// Test 5: Overflow
	ptr = ft_calloc(SIZE_MAX, 2);
	printf("Test 5: overflow, puntero = %p (debe ser NULL)\n", (void *)ptr);

	return (0);
}*/