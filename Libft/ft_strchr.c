/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:07:20 by hlucas            #+#    #+#             */
/*   Updated: 2021/11/30 16:07:20 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*fin;

	i = 0;
	fin = (char *)s;
	if (c == 0)
	{
		while (fin[i] != '\0')
			i++;
		return (&fin[i]);
	}
	while ((fin[i] != '\0') && (fin[i] != c))
		i++;
	if (fin[i] == '\0')
		return (NULL);
	return (&fin[i]);
}
