/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:53:40 by seflores          #+#    #+#             */
/*   Updated: 2025/12/05 12:04:50 by seflores         ###   ########.fr       */
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
