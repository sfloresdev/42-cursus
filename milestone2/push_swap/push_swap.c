/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:05:06 by seflores          #+#    #+#             */
/*   Updated: 2026/01/28 22:53:49 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	//t_stack	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	ft_parse_args(argc, argv, &stack_a);
	ft_index_stack(stack_a);
	size = ft_stack_size(stack_a);
	if (size == 2)
	{
		if (stack_a->value > stack_a->next->value)
			sa(&stack_a);
	}
	else if (size == 3)
		sort_three(&stack_a);
	else if (size >= 4)
		ft_radix_sort(&stack_a, &stack_b);
	/* tmp = stack_a;
	ft_printf("--- Result ---\n");
	while (tmp)
	{
		ft_printf("%d | Indice %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	} */
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
