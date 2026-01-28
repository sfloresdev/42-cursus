/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:49:05 by seflores          #+#    #+#             */
/*   Updated: 2026/01/28 16:13:51 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* Gestion de los nodos */
t_stack				*ft_stack_new(int value);
t_stack				*ft_stack_last(t_stack *stack);
void				ft_stack_add_back(t_stack **stack, t_stack *new_node);
int					ft_stack_size(t_stack *stack);

/* Parser - Validaciones */
int					ft_check_duplicates(t_stack *a, int n);
long				ft_atol(char *str, t_stack **stack);

/* utils - Limpieza */
void				ft_error_exit(t_stack **a, t_stack **b);
void				free_stack(t_stack **stack);

#endif