/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:53:40 by seflores          #+#    #+#             */
/*   Updated: 2025/12/06 22:34:56 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long ptr, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		ft_putptr(ptr / 16, count);
	ft_putchar(base[ptr % 16], count);
}

void 	print_pointer(unsigned long ptr, int *count)
{
	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	ft_putptr(ptr, count);
}