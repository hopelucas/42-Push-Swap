#include<unistd.h>

int	ft_tolower(int i)
{
	if (i > 64 && i < 91)
		return (i + 32);
	else
		return (i);
}
