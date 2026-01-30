/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:52:50 by seflores          #+#    #+#             */
/*   Updated: 2026/01/30 12:13:04 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_matrix(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

/*
Verificar que no esta repetido positivo o negativo
*/
int	ft_check_duplicates(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/*
Atoi mejorado, pensado para aceptar numeros negativos
*/
long	ft_atol(char *str, t_stack **stack, char **args)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if ( *str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		ft_free_error(stack, args);
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if (*str != '\0' || result * sign > INT_MAX || result * sign < INT_MIN)
		ft_free_error(stack, args);
	return (result * sign);
}

static void	ft_process_args(char **args, t_stack **stack_a)
{
	long	n;
	int		i;

	i = 0;
	while (args[i])
	{
		n = ft_atol(args[i], stack_a, args);
		if (ft_check_duplicates(*stack_a, (int)n))
		{
			ft_free_matrix(args);
			ft_error_exit(stack_a, NULL);
		}
		ft_stack_add_back(stack_a, ft_stack_new((int)n));
		i++;
	}
}

/*
Programa principal que parsea los argumentos de consola
*/
void	ft_parse_args(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	char	**args;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args || !*args)
		{
			if (args)
				ft_free_matrix(args);
			ft_error_exit(stack_a, NULL);
		}
		ft_process_args(args, stack_a);
		ft_free_matrix(args);
		i++;
	}
}
