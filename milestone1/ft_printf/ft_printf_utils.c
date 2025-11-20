/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:07:37 by seflores          #+#    #+#             */
/*   Updated: 2025/11/20 18:10:06 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count++;
}

void	ft_putnbr(int nbr, int *count)
{
	long	number;

	number = (long)nbr;
	if (number < 0)
	{
		number *= -1;
		ft_putchar('-', count);
	}
	if (number < 10)
		ft_putchar(number + '0', count);
	if (number >= 10)
	{
		ft_putnbr(number / 10, count);
		ft_putnbr(number % 10, count);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr_base(unsigned int nbr, char *base, int *count)
{
	long	number;
	int		length;

	length = ft_strlen(base);
	if (length < 2)
		return ;
	number = nbr;
	if (number < 0)
	{
		number *= -1;
		ft_putchar('-', count);
	}
	if (number < length)
		ft_putchar(base[number], count);
	if (number >= length)
	{
		ft_putnbr_base(number / length, base, count);
		ft_putnbr_base(number % length, base, count);
	}
}
