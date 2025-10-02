#include "libft.h"

int	main(void)
{
	printf("%d\n", ft_isalnum('{'));
	printf("---------ISASCII------\n");
	printf("%d\n", ft_isascii('3'));
	printf("%d\n", ft_isascii('~'));
	printf("---------ISPRINT------\n");
	printf("%d\n", ft_isprint('>'));
	printf("%d\n", ft_isprint('\t'));
	printf("---------STRLEN------\n");
        printf("%d\n", ft_strlen("Hola"));
        printf("%d\n", ft_strlen("Sergio  "));
	printf("%c\n", ft_toupper('u'));
	printf("%c\n", ft_toupper('a'));
	printf("---------tolower------\n");
        printf("%d\n", ft_tolower('N'));
        printf("%d\n", ft_tolower('S'));
	
	const char	*text = "Hola sergio";
	char	*ptr;

	ptr = ft_strchr(text, 'e');

	if (ptr != NULL)
	{
		printf("Se ha encontrado %s\n", ptr);
	}
	else
	{
		printf("No se ha encontrado coicidencia\n");
	}
	return (0);
}
