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



	






	printf("-------STRNCMP----------\n");

	    const char *tests[][2] = {
        {"hola", "hola"},    // iguales
        {"hola", "holb"},    // última letra distinta
        {"holc", "hola"},    // diferencia positiva
        {"", ""},            // vacías
        {"abc", "abcd"},     // prefijo
        {"abcd", "abc"},     // prefijo inverso
        {"á", "a"},          // carácter extendido
        {"ñ", "n"},          // carácter extendido
    };

    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    size_t n; // número de caracteres a comparar

    for (size_t i = 0; i < n_tests; i++) {
        // probamos varios tamaños n
        for (n = 0; n <= 5; n++) {
            int std = strncmp(tests[i][0], tests[i][1], n);
            int ft  = ft_strncmp(tests[i][0], tests[i][1], n);
            printf("Test %zu, n=%zu: \"%s\" vs \"%s\"\n", i+1, n, tests[i][0], tests[i][1]);
            printf("strncmp   = %d\n", std);
            printf("ft_strncmp= %d\n", ft);
            printf("%s\n\n", (std == ft) ? "OK" : "FAIL");
        }
    }


	printf("--------MEMSET--------\n");
	
	    char buf_std[5];
    char buf_ft[5];

    // ---------------- Test 1 ----------------
    memset(buf_std, 'X', 5);
    ft_memset(buf_ft, 'X', 5);

    printf("Test 1 (lleno con 'X'):\n");
    printf("memset : ");
    for (int i = 0; i < 5; i++)
        printf("%c ", buf_std[i]);
    printf("\nft_memset: ");
    for (int i = 0; i < 5; i++)
        printf("%c ", buf_ft[i]);
    printf("\n\n");

    // ---------------- Test 2 ----------------
    memset(buf_std, 0, 5);
    ft_memset(buf_ft, 0, 5);

    printf("Test 2 (lleno con 0):\n");
    printf("memset : ");
    for (int i = 0; i < 5; i++)
        printf("%d ", buf_std[i]);
    printf("\nft_memset: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", buf_ft[i]);
    printf("\n\n");

    // ---------------- Test 3 ----------------
    memset(buf_std, 200, 5);
    ft_memset(buf_ft, 200, 5);

    printf("Test 3 (lleno con 200):\n");
    printf("memset : ");
    for (int i = 0; i < 5; i++)
        printf("%d ", (unsigned char)buf_std[i]);
    printf("\nft_memset: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", (unsigned char)buf_ft[i]);
    printf("\n");


	return (0);
}
