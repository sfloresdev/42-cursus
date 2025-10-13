#include "libft.h"


void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char *str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char) c)
			return (c);	
		i++;
	}
	return (NULL);
}


int	main(void)
{
	return (0);
}
