#include "libft.h"

int	ft_isalpha(int i)
{
	if ((i > 64 && i < 91) || (i > 96 && i <= 122))
		return (1);
	return (0);
}
