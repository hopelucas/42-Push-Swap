#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	a = b;
	while (len)
	{
		*a = c;
		a++;
		len--;
	}
	return (b);
}
