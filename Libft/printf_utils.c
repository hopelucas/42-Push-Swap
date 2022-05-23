/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:07:20 by hlucas            #+#    #+#             */
/*   Updated: 2022/05/23 17:07:58 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_uint(unsigned int n, int fd, int *count)
{
	if (n >= 10)
		put_uint(n / 10, fd, count);
	ft_putchar_fd(n % 10 + '0', fd);
	(*count)++;
}

void	write_uint(unsigned int n, int *count)
{
	put_uint(n, 1, count);
}

int	num_len(int i)
{
	int	len;

	len = 0;
	if (i <= 0)
		len = 1;
	else
		len = 0;
	while (i != 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

int	write_int(int i)
{
	ft_putnbr_fd(i, 1);
	return (num_len(i));
}

int	write_str(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
