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
        //printf("%d\n", ft_strlen("Hola"));
        //printf("%d\n", ft_strlen("Sergio  "));
	printf("%c\n", ft_toupper('u'));
	printf("%c\n", ft_toupper('a'));
	printf("---------tolower------\n");
        printf("%d\n", ft_tolower('N'));
        printf("%d\n", ft_tolower('S'));
	printf("---------strchr------\n");
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

	printf("---------atoi------\n");
	char	*num = "+4525";
	char    *num2 = "+";
	char    *num3 = "123abc456";
	char    *num4 = " ";
	printf("%d\n", ft_atoi(num));
	printf("%d\n", ft_atoi(num2));
	printf("%d\n", ft_atoi(num3));
	printf("%d\n", ft_atoi(num4));
	printf("-------strrchr-------\n");	


	    const char *s1 = "Hola mundo";
    const char *s2 = "aaaaaa";
    const char *s3 = "";
    const char *s4 = "abc\0def"; // la cadena termina en '\0'

    // 1. Última ocurrencia normal
    printf("Test 1: %s\n", ft_strrchr(s1, 'o'));          // Esperado: apunta a "o mundo"
    printf("     original: %s\n", strrchr(s1, 'o'));

    // 2. Carácter no presente
    printf("Test 2: %p\n", ft_strrchr(s1, 'z'));          // Esperado: NULL
    printf("     original: %p\n", strrchr(s1, 'z'));

    // 3. Última letra repetida
    printf("Test 3: %s\n", ft_strrchr(s2, 'a'));          // Esperado: apunta al último "a"
    printf("     original: %s\n", strrchr(s2, 'a'));

    // 4. Terminador nulo
    printf("Test 4: %s\n", ft_strrchr(s1, '\0'));         // Esperado: apunta al '\0' final
    printf("     original: %s\n", strrchr(s1, '\0'));

    // 5. Cadena vacía
    printf("Test 5: %p\n", ft_strrchr(s3, 'a'));          // Esperado: NULL
    printf("     original: %p\n", strrchr(s3, 'a'));

    // 6. Carácter tras '\0' (no debería encontrarse)
    printf("Test 6: %p\n", ft_strrchr(s4, 'd'));          // Esperado: NULL
    printf("     original: %p\n", strrchr(s4, 'd'));

    return 0;
	return (0);
}
