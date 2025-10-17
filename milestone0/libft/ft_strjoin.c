/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:52:40 by seflores          #+#    #+#             */
/*   Updated: 2025/10/16 10:31:50 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	string = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		string[i + j] = s2[j];
		j++;
	}
	string[i + j] = '\0';
	return (string);
}
/*
int	main(void)
{
	char *res;

	// 1. Casos normales
	res = ft_strjoin("Hola", "Mundo");
	if (res && strcmp(res, "HolaMundo") == 0)
		printf("Test 1 OK\n");
	else
		printf("Test 1 FAIL\n");
	free(res);

	// 2. Primera cadena vacía
	res = ft_strjoin("", "Mundo");
	if (res && strcmp(res, "Mundo") == 0)
		printf("Test 2 OK\n");
	else
		printf("Test 2 FAIL\n");
	free(res);

	// 3. Segunda cadena vacía
	res = ft_strjoin("Hola", "");
	if (res && strcmp(res, "Hola") == 0)
		printf("Test 3 OK\n");
	else
		printf("Test 3 FAIL\n");
	free(res);

	// 4. Ambas cadenas vacías
	res = ft_strjoin("", "");
	if (res && strcmp(res, "") == 0)
		printf("Test 4 OK\n");
	else
		printf("Test 4 FAIL\n");
	free(res);

	// 5. NULL como primera cadena
	res = ft_strjoin(NULL, "Mundo");
	if (!res)
		printf("Test 5 OK (NULL)\n");
	else
	{
		printf("Test 5 FAIL\n");
		free(res);
	}

	// 6. NULL como segunda cadena
	res = ft_strjoin("Hola", NULL);
	if (!res)
		printf("Test 6 OK (NULL)\n");
	else
	{
		printf("Test 6 FAIL\n");
		free(res);
	}

	// 7. Ambas NULL
	res = ft_strjoin(NULL, NULL);
	if (!res)
		printf("Test 7 OK (NULL)\n");
	else
	{
		printf("Test 7 FAIL\n");
		free(res);
	}

	return (0);
}*/

