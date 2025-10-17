/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:17:57 by seflores          #+#    #+#             */
/*   Updated: 2025/10/15 23:33:49 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	num_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*string;
	long	num;
	size_t	len;

	len = num_len(n);
	string = malloc(len + 1);
	if (!string)
		return (NULL);
	num = n;
	if (num < 0)
		num = -num;
	string[len] = '\0';
	if (n == 0)
	{
		string[0] = '0';
		return (string);
	}
	while (num > 0)
	{
		string[--len] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		string[0] = '-';
	return (string);
}
/*
int main(void)
{
    int test_cases[] = {0, 5, -7, 12345, -9876, 2147483647, -2147483648, 1000, -1002, -1};
    size_t n = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < n; i++)
    {
        char *result = ft_itoa(test_cases[i]);
        if (result)
        {
            printf("ft_itoa(%d) = \"%s\"\n", test_cases[i], result);
            free(result); // No olvidar liberar la memoria
        }
        else
        {
            printf("ft_itoa(%d) = NULL (malloc failed)\n", test_cases[i]);
        }
    }
    return 0;
}*/

