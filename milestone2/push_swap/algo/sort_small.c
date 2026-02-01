/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:11:24 by seflores          #+#    #+#             */
/*   Updated: 2026/02/01 19:56:04 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_find_highest(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

static int	get_min_pos(t_stack *stack)
{
	int	min;
	int	min_pos;
	int	i;

	min = stack->value;
	min_pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_pos);
}
static void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;
	int	size;

	size = ft_stack_size(*stack_a);
	min_pos = get_min_pos(*stack_a);
	if (min_pos > size / 2)
	{
		while (min_pos < size)
		{
			rra(stack_a);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
	pb(stack_a, stack_b);
}

void	sort_three(t_stack **a)
{
	int	max;

	if (ft_stack_size(*a) != 3)
		return ;
	max = ft_find_highest(*a);
	if ((*a)->value == max)
		ra(a);
	else if ((*a)->next->value == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int size;

	size = ft_stack_size(*stack_a);
	while (size > 3)
	{
		push_to_b(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}