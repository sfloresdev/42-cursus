/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:05:06 by seflores          #+#    #+#             */
/*   Updated: 2026/01/12 19:55:13 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;

    i = 0;
    while (i < argc){
        if (ft_not_repeated(argv[i]))
            ft_printf("Error\n");
        i++;
    }
    ft_printf("The argument count is %d", argc);
    
    return (0);
}