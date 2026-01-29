/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:21:59 by seflores          #+#    #+#             */
/*   Updated: 2026/01/29 09:45:18 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (a && *a && (*a)->next)
	{
		first = *a;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
	if (b && *b && (*b)->next)
	{
		first = *b;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*b = second;
	}
	ft_printf("ss\n");
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (a && *a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		last = ft_stack_last(*a);
		last->next = tmp;
	}
	if (b && *b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		last = ft_stack_last(*b);
		last->next = tmp;
	}
	ft_printf("rr\n");
}

static void	rrr_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*penultimate;

	last = *stack;
	penultimate = NULL;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_stack **a, t_stack **b)
{
	if (a && *a && (*a)->next)
		rrr_stack(a);
	if (b && *b && (*b)->next)
		rrr_stack(b);
	ft_printf("rrr\n");
}
