/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:52:50 by seflores          #+#    #+#             */
/*   Updated: 2026/01/12 20:00:05 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* // Verificar que sea numero
int ft_is_number(char *str)
{
    
} */


// Verificar que no esta repetido positivo o negativo

int ft_not_repeated(char *str)
{
    size_t  i;
    size_t  j;

    i = 1;
    while (str[i]) {
        j = i + 1;
        while (str[j]) {
            if (str[i] == str[j]) {
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

/* 
// Verificar caso de ir entre comillas

int ft_check_quotes() */



// Verficar que no haya dos signos seguidos, usar atoi pero que acepte varios
// signos


