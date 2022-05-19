#include "../includes/push_swap.h"

static int	ft_check_nb(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '-')
			i++;
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (-1);
	}
	return (0);
}

static int	ft_check_int(char *arg)
{
	long int	nb;

	nb = ft_atoi(arg);
	if (nb < -2147483648 || nb > 2147483647)
		return (-1);
	return (0);
}

static int	ft_check_dup(char *arg, char **argv, int i)
{
	long int	nb;

	nb = ft_atoi(arg);
	while (argv[i + 1])
	{
		if (nb == ft_atoi(argv[i + 1]))
			return (-1);
		i++;
	}
	return (0);
}

static	int	ft_error_msg(int code)
{
	write(2, "Error\n", 6);
	if (code == 1)
	{
		write(2, "At least one argument is not a number\n", 38);
		exit(1);
	}
	else if (code == 2)
	{
		write(2, "At least one argument is bigger than an integer\n", 48);
		exit(2);
	}
	else if (code == 3)
	{
		write(2, "At least one argument is duplicate\n", 35);
		exit(3);
	}
	return (-1);
}

int	ft_error(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (ft_check_nb(argv[i]) != 0)
			return (ft_error_msg(1));
	i = 0;
	while (argv[++i])
		if (ft_check_int(argv[i]) != 0)
			return (ft_error_msg(2));
	i = 0;
	while (argv[++i])
		if (ft_check_dup(argv[i], argv, i) != 0)
			return (ft_error_msg(3));
	return (0);
}