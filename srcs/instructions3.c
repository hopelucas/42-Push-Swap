/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:36:30 by hlucas            #+#    #+#             */
/*   Updated: 2022/05/23 16:09:04 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_list **stack_a, t_list **stack_b, bool flag)
/*
rrr : ra and rb at the same time. */
{
	rra(stack_a, false);
	rrb(stack_b, false);
	if (flag)
		write(1, "rrr\n", 4);
}
