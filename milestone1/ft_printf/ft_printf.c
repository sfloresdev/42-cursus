/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seflores <seflores@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:03:08 by seflores          #+#    #+#             */
/*   Updated: 2025/12/12 12:38:51 by seflores         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_convert(const char c, va_list ap, int *count)
{
	char	*lower_hexa;
	char	*upper_hexa;

	lower_hexa = "0123456789abcdef";
	upper_hexa = "0123456789ABCDEF";
	if (c == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (c == '%')
		ft_putchar('%', count);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), count);
	else if (c == 'u')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789", count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), lower_hexa, count);
	else if (c == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), upper_hexa, count);
	else if (c == 'p')
		print_pointer(va_arg(ap, unsigned long), count);
	else
		ft_putchar(c, count);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		count;
	size_t	i;

	if (!str)
		return (-1);
	va_start(ap, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			printf_convert(str[i], ap, &count);
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}

/* int	main(void)
{
	int hexa_decimal = 42;
	int negativo = -23;
	int edad = 19;
	int *null_pointer = NULL;
	char *str = NULL;
	char *str_2 = "Sergio Flores";
	char c = 's';
	char c_null = '\0';

	ft_printf("---- NULL COUNT ----\n\n");

	    printf("=== TEST 1: Caso normal (debería funcionar) ===\n");
    char *empty_str = NULL;
    ft_printf("String NULL: %s\n", empty_str);
    printf("✓ Test 1 pasado\n\n");

    printf("=== TEST 2: ft_putstr directamente con NULL ===\n");
    printf("Llamando directamente ft_putstr con NULL...\n");
    int counter = 0;
    
    ft_putstr(NULL, &counter);
    printf("\n✓ Test 2 pasado (counter = %d)\n\n", counter);

    printf("=== TEST 3: ft_putstr está bien implementado ===\n");
    printf("No hay recursión infinita.\n\n");

    printf("=== TEST 4: Problema - formato termina con %% ===\n");
    printf("ft_printf: Test con porcentaje al final: ");
    int result2 = ft_printf("texto%");
    printf(" (ret=%d)\n", result2);
    printf("Nota: El caracter despues de %% es '\\0' (nulo)\n\n");
    
    printf("=== TEST 5: Conversión no reconocida ===\n");
    printf("ft_printf: ");
    result2 = ft_printf("valor: %z\n", 42);
    printf("(ret=%d)\n", result2);
    printf("Nota: %%z no es válido, debería imprimir algo o ignorarlo\n\n");
    
    printf("=== TEST 6: Múltiples %% seguidos ===\n");
    result2 = ft_printf("test: %%% texto\n");
    printf("(ret=%d)\n\n", result2);
	
	ft_printf("---- Caracteres ----\n");

	printf("original: Asi se ve un caracter = %c\n", c);
	ft_printf("ft: Asi se ve un caracter = %c\n", c);

	ft_printf("-------\n");

	printf("original: Asi se ve un caracter NULL = %c\n", c_null);
	ft_printf("ft: Asi se ve un caracter NULL = %c\n", c_null);
	
	printf("---- Punteros ----\n");
	
	printf("original: El valor de un puntero nulo se ve asi %p\n", null_pointer);
	ft_printf("ft: El valor de un puntero nulo se ve asi %p\n", null_pointer);


	printf("original: El valor de un puntero | %p\n", &edad);
	ft_printf("ft: El valor de un puntero | %p\n", &edad);

	printf("---- Cadenas normales ---\n");
	
	printf("original: Hola buenos dias me llamo Sergio\n");
	ft_printf("ft: Hola buenos dias me llamo Sergio\n");
	
	ft_printf("-------\n");

	printf("original: Asi se ve una string vacia = %s\n", str);
	ft_printf("ft: Asi se ve una string vacia = %s\n", str);

	ft_printf("-------\n");

	printf("original: Asi se ve una string = %s\n", str_2);
	ft_printf("ft: Asi se ve una string = %s\n", str_2);
	
	
	printf("---- NUMEROS ----\n");
	// DECIMAL
	printf("original: Hola tengo %d agnos\n", edad);
	ft_printf("ft: Hola tengo %d agnos\n", edad);

	printf("-------\n");
	
	printf("original: Un numero entero 'i' %i \n", edad);
	ft_printf("ft: Un numero entero 'i' %i \n", edad);

	printf("-------\n");
	
	printf("original: Un numero entero sin signo 'u' %u \n", edad);
	ft_printf("ft: Un numero entero sin signo 'u' %u \n", edad);

	printf("-------\n");
	
	printf("original: Un numero entero sin signo 'u'  %u \n", negativo);
	ft_printf("ft: Un numero entero sin signo 'u' %u \n", negativo);

	printf("-------\n");
	
	printf("original: Un numero hexadecimal lower_case %x \n", hexa_decimal);
	ft_printf("ft: Un numero hexadecimal lower_case %x \n", hexa_decimal);

	printf("-------\n");
	
	printf("original: Un numero hexadecimal upper_case %X \n", hexa_decimal);
	ft_printf("ft: Un numero hexadecimal upper_case %X \n", hexa_decimal);

	printf("---- Porcentaje ----\n");
	
	printf("original: Me gusta el porcentaje -> %%, mira  -> %%n %%24\n");
	ft_printf("ft: Me gusta el porcentaje -> %%, mira  -> %%n %%24 \n");
	
	return (0);
} */
