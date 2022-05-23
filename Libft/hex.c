/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:07:20 by hlucas            #+#    #+#             */
/*   Updated: 2022/05/23 17:09:16 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_hex_static(size_t n, char *base, int *count)
{
	if (n >= 16)
		put_hex_static(n / 16, base, count);
	ft_putchar_fd(base[n % 16], 1);
	(*count)++;
}

int	put_pointer(void *pointer, int *count)
{
	ft_putstr_fd("0x", 1);
	put_hex_static((size_t)pointer, "0123456789abcdef", count);
	return (2);
}

void	put_hex(unsigned int n, int *count, char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	put_hex_static(n, base, count);
}
