/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:05:40 by seflores          #+#    #+#             */
/*   Updated: 2026/01/29 09:54:29 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.
*/
void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	ft_printf("sa\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!b || !*b)
		return ;
	node = *b;
	*b = (*b)->next;
	node->next = *a;
	*a = node;
	ft_printf("pa\n");
}

void	ra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	last = ft_stack_last(*a);
	last->next = tmp;
	ft_printf("ra\n");
}

void	rra(t_stack **a)
{
	t_stack		*last;
	t_stack		*penultimate;

	if (!a || !(*a) || !(*a)->next)
		return ;
	last = *a;
	penultimate = NULL;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
	last->next = *a;
	*a = last;
	ft_printf("rra\n");
}
