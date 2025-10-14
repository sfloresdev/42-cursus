/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:59:07 by seflores          #+#    #+#             */
/*   Updated: 2025/10/14 17:59:11 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		ch;

	ch = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

int	main(void)
{
	const char	test1[] = "Hola mundo";
	const char	test2[] = "abcdef";
	const char	test4[] = "";
	void		*res_libc;
	void		*res_ft;
	const char	test3[] = "123\045";

	// incluye un carácter especial '\045' (octal 37)
	// 1. Caracter en medio
	res_libc = memchr(test1, 'm', strlen(test1));
	res_ft = ft_memchr(test1, 'm', strlen(test1));
	printf("Test 1: %s\n", (res_ft == res_libc) ? "OK" : "FAIL");
	// 2. Caracter al principio
	res_libc = memchr(test2, 'a', strlen(test2));
	res_ft = ft_memchr(test2, 'a', strlen(test2));
	printf("Test 2: %s\n", (res_ft == res_libc) ? "OK" : "FAIL");
	// 3. Caracter al final
	res_libc = memchr(test2, 'f', strlen(test2));
	res_ft = ft_memchr(test2, 'f', strlen(test2));
	printf("Test 3: %s\n", (res_ft == res_libc) ? "OK" : "FAIL");
	// 4. Caracter no presente
	res_libc = memchr(test2, 'z', strlen(test2));
	res_ft = ft_memchr(test2, 'z', strlen(test2));
	printf("Test 4: %s\n", (res_ft == res_libc) ? "OK" : "FAIL");
	// 5. Caracter nulo
	res_libc = memchr(test1, '\0', strlen(test1) + 1);
	res_ft = ft_memchr(test1, '\0', strlen(test1) + 1);
	printf("Test 5: %s\n", (res_ft == res_libc) ? "OK" : "FAIL");
	// 6. n = 0
	res_libc = memchr(test2, 'a', 0);
	res_ft = ft_memchr(test2, 'a', 0);
	printf("Test 6: %s\n", (res_ft == res_libc) ? "OK" : "FAIL");
	// 7. Caracter fuera del rango ASCII normal (>127)
	res_libc = memchr(test3, 037, sizeof(test3));
	res_ft = ft_memchr(test3, 037, sizeof(test3));
	printf("Test 7: %s\n", (res_ft == res_libc) ? "OK" : "FAIL");
	// 8. Cadena vacía
	res_libc = memchr(test4, 'a', 1);
	res_ft = ft_memchr(test4, 'a', 1);
	printf("Test 8: %s\n", (res_ft == res_libc) ? "OK" : "FAIL");
	return (0);
}
