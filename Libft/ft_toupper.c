#include "libft.h"

int	ft_toupper(int i)
{
	if (i > 96 && i < 123)
		return (i - 32);
	else
		return (i);
}
