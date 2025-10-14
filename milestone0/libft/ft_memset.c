#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	buffer1[20];
	char	buffer2[20];

	// Rellenamos ambos buffers con '-'
	memset(buffer1, '-', sizeof(buffer1));
	memset(buffer2, '-', sizeof(buffer2));
	// Usamos ft_memset para poner 'A' en los primeros 10 bytes
	ft_memset(buffer1, 'A', 10);
	// Usamos memset de la librería estándar para comparar
	memset(buffer2, 'A', 10);
	// Mostramos resultados
	printf("Resultado con ft_memset : %.*s\n", (int)sizeof(buffer1), buffer1);
	printf("Resultado con memset    : %.*s\n", (int)sizeof(buffer2), buffer2);
	return (0);
}*/
