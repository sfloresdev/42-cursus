/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:27:42 by seflores          #+#    #+#             */
/*   Updated: 2025/10/14 17:23:13 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	char	sign;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str - 48;
		str++;
	}
	return (result * sign);
}

int	main(void)
{
	const char *tests[] = {"42",
							"   42",
							"-42",
							"+42",
							"2147483647",  // INT_MAX
							"-2147483648", // INT_MIN
							"2147483648",  // Overflow
							"-2147483649", // Underflow
							"0000123",
							"  -00123abc",
							"abc123",
							"",
							"  \t\n\r\v\f123",
							"+-42",
							"--42",
							"9223372036854775807", // Más allá de int
							"-9223372036854775808",
							"9999999999999999999999999"};

	size_t n_tests = sizeof(tests) / sizeof(tests[0]);

	for (size_t i = 0; i < n_tests; i++)
	{
		int my_result = ft_atoi(tests[i]);
		int std_result = atoi(tests[i]);
		printf("Test: \"%s\"\n", tests[i]);
		printf("ft_atoi: %d\n", my_result);
		printf("atoi   : %d\n", std_result);
		printf("--------------------\n");
	}

	return (0);
}