/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:14:23 by seflores          #+#    #+#             */
/*   Updated: 2025/10/22 18:19:07 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;
	int		in_word;

	i = 0;
	words = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			words++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (words);
}

static char	**free_pointers(char **array)
{
	size_t	i;

	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static	char	check_null(char ***array, char const *s, char c)
{
	if (!s)
		return (0);
	*array = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!*array)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**array;
	size_t			i;
	size_t			word;
	size_t			start;

	if (!check_null(&array, s, c))
		return (NULL);
	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			array[word] = ft_substr(s, start, (i - start));
			if (!array[word++])
				return (free_pointers(array));
		}
	}
	array[word] = NULL;
	return (array);
}
