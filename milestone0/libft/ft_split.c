/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:14:23 by seflores          #+#    #+#             */
/*   Updated: 2025/10/17 21:47:14 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;
	int		new_word;

	i = 0;
	words = 0;
	new_word = 0;
	while (s[i])
	{
		if (s[i] != c && !new_word)
		{
			new_word = 1;
			words++;
		}
		else if (s[i] == c)
		{
			new_word = 0;
		}
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		pointers;

	pointers = count_words(s, c);
    array = malloc(sizeof(char *) * (pointers  + 1));
    if (!array)
        return (NULL);

    
    
	return (array);
}

int	main(void)
{
	return (0);
}