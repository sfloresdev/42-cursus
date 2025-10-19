/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:14:23 by seflores          #+#    #+#             */
/*   Updated: 2025/10/19 19:10:13 by seflores         ###   ########.fr       */
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
/*
static char	*g_word(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start) + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}*/

static int	get_first_word(char const *s, char c, int *index)
{
	*index = 0;
	while (s[*index] && s[*index] == c)
		(*index)++;
	return (*index);
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

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		word;
	int		start;

	array = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array || !s)
		return (NULL);
	word = 0;
	start = get_first_word(s, c, &i);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			array[word] = ft_substr(s, start, (i - start) + 1);
			if (!array[word++])
				return (free_pointers(array));
			while (s[i + 1] && s[i + 1] == c)
				i++;
			start = i + 1;
		}
		i++;
	}
	array[word] = NULL;
	return (array);
}
