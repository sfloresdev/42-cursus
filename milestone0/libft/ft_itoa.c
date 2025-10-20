/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:17:57 by seflores          #+#    #+#             */
/*   Updated: 2025/10/22 13:26:29 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(int n)
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
