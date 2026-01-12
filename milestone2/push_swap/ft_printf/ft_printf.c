/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:03:08 by seflores          #+#    #+#             */
/*   Updated: 2025/12/12 19:18:43 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_convert(const char c, va_list ap, int *count)
{
	char	*lower_hexa;
	char	*upper_hexa;

	lower_hexa = "0123456789abcdef";
	upper_hexa = "0123456789ABCDEF";
	if (c == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (c == '%')
		ft_putchar('%', count);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), count);
	else if (c == 'u')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789", count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), lower_hexa, count);
	else if (c == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), upper_hexa, count);
	else if (c == 'p')
		print_pointer(va_arg(ap, unsigned long), count);
	else
		ft_putchar(c, count);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		count;
	size_t	i;

	if (!str)
		return (-1);
	va_start(ap, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			printf_convert(str[i], ap, &count);
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}
