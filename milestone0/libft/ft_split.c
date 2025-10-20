/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:14:23 by seflores          #+#    #+#             */
/*   Updated: 2025/10/20 19:09:21 by seflores         ###   ########.fr       */
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

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	word = 0;
	start = get_first_word(s, c, &i);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			array[word] = ft_substr(&s[i], 0, (i - start) + 1);
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

/* #include <stdio.h>

int main()
{
// subtest 6: NULL string 
    {
        const char *s = NULL;
        char c = ' ';
        char **got = ft_split(s, c);
        
        if (got == NULL) printf("OK");
        else
        {
            printf("expected NULL for NULL string");
			int k = 0;
            while(got[k])
			{
				free(got[k]);
				k++;
			}
			free(got);
        }
    }
	return 0;
} */


/*
int	main()
{
	char	*string = "hola que tal estas";
	char	**res;

	res = ft_split(string, ' ');
	
	while (*res)
	{
		printf("%s\n", *res);
		*res++;
	}

	return (0);
}*/