/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:41:22 by seflores          #+#    #+#             */
/*   Updated: 2025/10/17 16:33:36 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;		
	write(fd, s, ft_strlen(s));	
}
/*
int	main(void)
{
	// 1️⃣ Cadena normal
	ft_putstr_fd("Hola mundo", 1);
	ft_putstr_fd("\n", 1);

	// 2️⃣ Cadena con salto de línea
	ft_putstr_fd("Hola\nMundo\n", 1);

	// 3️⃣ Cadena con tabuladores
	ft_putstr_fd("Col1\tCol2\tCol3\n", 1);

	// 4️⃣ Cadena vacía
	ft_putstr_fd("", 1);

	// 5️⃣ Puntero NULL
	ft_putstr_fd(NULL, 1);

	return (0);
}*/

