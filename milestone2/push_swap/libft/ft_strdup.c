/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:46:26 by seflores          #+#    #+#             */
/*   Updated: 2025/10/22 18:46:49 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*string;

	string = malloc(ft_strlen(s) + 1);
	if (!string)
		return (NULL);
	ft_strlcpy(string, s, ft_strlen(s) + 1);
	return (string);
}
