#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}


int	main(void)
{

	    char buffer[10] = "abcdefgh";

    printf("Antes de ft_bzero: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", buffer[i]); // imprime valores ASCII
    printf("\n");

    ft_bzero(buffer, 10);

    printf("Después de ft_bzero: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", buffer[i]); // todos deberían ser 0
    printf("\n");


	return (0);
}
