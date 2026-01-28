/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:59:06 by seflores          #+#    #+#             */
/*   Updated: 2026/01/28 18:20:00 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	ft_printf("sb\n");
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("pb\n");
}

/*
Shift up all elements of stack b by 1.
The first element becomes the last one.
*/
void	rb(t_stack **b)
{
	t_stack *tmp;
	t_stack *last;

	if (!b || !*b || !(*b)->next)
		return ;

	tmp = *b;
	*b = (*b)->next;

	tmp->next = NULL;
	last = ft_stack_last(*b);
	last->next = tmp;
	ft_printf("rb\n");
}

/*
Shift down all elements of stack b by 1.
The last element becomes the first one.
*/
void rrb(t_stack **b)
{
    t_stack *last;
    t_stack *penultimate;

    if (!b || !*b || !(*b)->next)
        return ;
    
    last = *b;
    penultimate = NULL;
    
    while (last->next)
    {
        penultimate = last;
        last = last->next;
    }
    penultimate->next = NULL;
    last->next = *b;
    *b = last;
    ft_printf("rrb\n");
}