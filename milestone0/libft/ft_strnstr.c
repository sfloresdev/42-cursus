#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] && (little[j] == big[i + j]) && ((i + j) < len))
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *text = "Hola mundo";
    	const char *sub1 = "mundo";
    	const char *sub2 = "mun";
    	const char *sub3 = "Hola mundo!";
    	const char *sub4 = "";

    	char *res1 = ft_strnstr(text, sub1, 10);
    	char *res2 = ft_strnstr(text, sub2, 5);
    	char *res3 = ft_strnstr(text, sub3, 20);
    	char *res4 = ft_strnstr(text, sub4, 5);

    	printf("Buscando '%s' en '%s' con len=10: %s\n", sub1, text, res1 ? res1 : "NULL");
    	printf("Buscando '%s' en '%s' con len=5 : %s\n", sub2, text, res2 ? res2 : "NULL");
    	printf("Buscando '%s' en '%s' con len=20: %s\n", sub3, text, res3 ? res3 : "NULL");
    	printf("Buscando cadena vacía: %s\n", res4 ? res4 : "NULL");

    	// Comparación con la función estándar
    	char *std1 = strnstr(text, sub1, 10);
    	printf("Comparación con strnstr estándar: %s\n", std1 ? std1 : "NULL");

	return (0);
}*/
