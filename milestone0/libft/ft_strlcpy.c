#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}


int	main(void)
{
	    struct test_case {
        const char *src;
        size_t size;
    } tests[] = {
        {"Hola mundo", 6},
        {"Hola", 10},
        {"", 5},
        {"12345", 0},
        {"12345", 5}
    };

    char dst1[20];
    char dst2[20];

    for (int t = 0; t < 5; t++)
    {
        memset(dst1, 'X', sizeof(dst1)); // llenar con basura
        memset(dst2, 'X', sizeof(dst2));

        size_t ret1 = ft_strlcpy(dst1, tests[t].src, tests[t].size);
        size_t ret2 = strlcpy(dst2, tests[t].src, tests[t].size);

        printf("Test %d: src='%s', size=%zu\n", t+1, tests[t].src, tests[t].size);
        printf("  ft_strlcpy: dst='%s', return=%zu\n", dst1, ret1);
        printf("  strlcpy   : dst='%s', return=%zu\n", dst2, ret2);

        if (ret1 == ret2 && strcmp(dst1, dst2) == 0)
            printf("  Resultado: OK ✅\n\n");
        else
            printf("  Resultado: FAILED ❌\n\n");
    }

	return (0);
}
