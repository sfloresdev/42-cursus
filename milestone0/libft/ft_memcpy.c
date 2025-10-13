#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int	main(void)
{

	    char src1[] = "Hola mundo";
    char dest1[20];
    ft_memcpy(dest1, src1, 11);  // Incluye '\0'
    printf("Test 1 - Copia básica:\n");
    printf("Resultado: %s\n\n", dest1);

    // 2️⃣ Copia parcial (sin incluir el terminador nulo)
    char src2[] = "Libft";
    char dest2[10] = {0};
    ft_memcpy(dest2, src2, 3); // Copia solo 'L', 'i', 'b'
    printf("Test 2 - Copia parcial:\n");
    printf("Resultado: %.3s\n\n", dest2);

    // 3️⃣ Copia de datos binarios (no cadenas)
    int nums_src[] = {1, 2, 3, 4, 5};
    int nums_dest[5] = {0};
    ft_memcpy(nums_dest, nums_src, sizeof(nums_src));
    printf("Test 3 - Datos binarios:\n");
    for (int i = 0; i < 5; i++)
        printf("%d ", nums_dest[i]);
    printf("\n\n");

    // 4️⃣ Copia con n = 0 (no debe hacer nada)
    char src4[] = "ABCDE";
    char dest4[] = "xxxxx";
    ft_memcpy(dest4, src4, 0);
    printf("Test 4 - n = 0:\n");
    printf("Resultado: %s\n\n", dest4);

    // 5️⃣ Caso con ambos punteros NULL
    printf("Test 5 - Punteros NULL:\n");
    void *res = ft_memcpy(NULL, NULL, 5);
    printf("Resultado: %s\n\n", res == NULL ? "NULL devuelto (correcto)" : "Error");

    // 6️⃣ (Extra) Comparación con memcpy estándar
    char src6[] = "Comparar memcpy";
    char dest6a[20], dest6b[20];
    ft_memcpy(dest6a, src6, 16);
    memcpy(dest6b, src6, 16);
    printf("Test 6 - Comparación con memcpy estándar:\n");
    printf("ft_memcpy: %s\n", dest6a);
    printf("memcpy:    %s\n", dest6b);

	return (0);
}
