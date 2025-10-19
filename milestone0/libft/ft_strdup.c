/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:46:26 by seflores          #+#    #+#             */
/*   Updated: 2025/10/18 21:33:22 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*string;

	string = malloc(ft_strlen(s) + 1);
	if (!string)
		return (NULL);
	ft_strlcpy(string, s, ft_strlen(s) + 1);
	return (string);
}
/*
void	test_strdup(const char *input, const char *expected, int test_num)
{
	char	*res;
	int		ok;

	res = ft_strdup(input);
	if (res == NULL && expected == NULL)
		ok = 1;
	else if (res != NULL && expected != NULL && strcmp(res, expected) == 0)
		ok = 1;
	else
		ok = 0;
	printf("Test %2d: %s\n", test_num, ok ? "OK" : "FAIL");
	free(res); // liberar memoria para evitar fugas
}

int	main(void)
{
	printf("=== CASOS NORMALES ===\n");

	test_strdup("Hola mundo", "Hola mundo", 1);   // cadena normal
	test_strdup("1234567890", "1234567890", 2);   // solo números
	test_strdup("A", "A", 3);                     // un solo carácter

	printf("\n=== CASOS EXTREMOS ===\n");

	test_strdup("", "", 4);                        // cadena vacía
	test_strdup(" ", " ", 5);                      // espacio
	test_strdup("\0", "\0", 6);
		// carácter nulo dentro de cadena (cuidado)

	// cadena muy larga
	char *long_str = malloc(10001);
	if (!long_str)
		return (1);
	for (int i = 0; i < 10000; i++)
		long_str[i] = 'a';
	long_str[10000] = '\0';
	test_strdup(long_str, long_str, 7);
	free(long_str);

	test_strdup("Line1\nLine2\tTab", "Line1\nLine2\tTab", 8);

	return (0);
}*/
