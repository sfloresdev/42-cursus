/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:03:36 by seflores          #+#    #+#             */
/*   Updated: 2026/01/12 19:13:05 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int nbr, int *count);
void	ft_putchar(char c, int *count);
void	ft_putnbr_base(unsigned int nbr, char *base, int *count);
void	printf_convert(const char c, va_list ap, int *count);
void	ft_putptr(unsigned long ptr, int *count);
void	print_pointer(unsigned long ptr, int *count);

#endif
