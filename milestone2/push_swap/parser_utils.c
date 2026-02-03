/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:08:00 by seflores          #+#    #+#             */
/*   Updated: 2026/02/03 16:50:59 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_error(t_stack **stack, char **args)
{
	ft_free_matrix(args);
	ft_error_exit(stack, NULL);
}
