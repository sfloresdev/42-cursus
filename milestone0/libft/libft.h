/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:48:13 by seflores          #+#    #+#             */
/*   Updated: 2025/10/02 20:36:27 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <string.h>

int	ft_isalpha(char c);
int	ft_isdigit(char c);
int	ft_isalnum(char c);
int	ft_isascii(char c);
int	ft_isprint(char c);
int	ft_strlen(const char *str);
int	ft_toupper(char c);
int	ft_tolower(char c);
char	*ft_strchr(const char *str, int c);
int	ft_atoi(const char *ptr);
char	*ft_strrchr(const char *str, int c);

#endif
