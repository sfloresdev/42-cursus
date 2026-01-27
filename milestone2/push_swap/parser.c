/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:52:50 by seflores          #+#    #+#             */
/*   Updated: 2026/01/22 18:08:56 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Programa principal que parsea los argumentos de consola
*/
void	ft_args_parser(void)
{
}

// Verificar que no esta repetido positivo o negativo
int	ft_has_duplicates(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
// Verificar caso de ir entre comillas
int	ft_check_quotes(void) */

/*
Atoi mejorado, pensado para aceptar numeros negativos
*/
int	ft_atoi_neg(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		*str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if (ft_isalpha(*str))
		ft_printf("Error: Not a valid type");
	return (result * sign);
}

int	ft_int_check(char *str)
{
	if (ft_isdigit)
		return (0);
}
