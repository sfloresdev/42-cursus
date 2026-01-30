/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:49:05 by seflores          #+#    #+#             */
/*   Updated: 2026/01/30 12:14:15 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>

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
void				ft_index_stack(t_stack *stack);

/* Parser - Validaciones */
int					ft_check_duplicates(t_stack *a, int n);
long				ft_atol(char *str, t_stack **stack, char **args);
void				ft_parse_args(int argc, char **argv, t_stack **stack_a);
void				ft_free_matrix(char **argv);

/* utils - Limpieza */
void				ft_error_exit(t_stack **a, t_stack **b);
void				free_stack(t_stack **stack);
int					ft_already_sorted(t_stack *stack);
void				ft_free_error(t_stack **stack, char **args);

/* Operations - Operaciones del subject */
void				sa(t_stack **a);
void				pa(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rra(t_stack **a);

void				sb(t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				rb(t_stack **b);
void				rrb(t_stack **b);

void				ss(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);

/* Algo - Algoritmos de ordenacion */
void				sort_three(t_stack **a);
void				ft_radix_sort(t_stack **stack_a, t_stack **stack_b);

#endif