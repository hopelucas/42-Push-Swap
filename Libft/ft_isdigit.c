#include "libft.h"

int	ft_isdigit(int i)
{
	if (i > 47 && i < 58)
		return (1);
	return (0);
}
