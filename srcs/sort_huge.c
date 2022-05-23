/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:36:30 by hlucas            #+#    #+#             */
/*   Updated: 2022/05/23 17:03:30 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	second(t_list **stack_a, t_list **stack_b, t_median *median);
static void	third(t_list **stack_a, t_list **stack_b, t_median *median);
static void	fourth(t_list **stack_a, t_list **stack_b, t_median *median);

void	sort_eighths(t_list **stack_a, t_list **stack_b)
{
	t_median	*median;

	median = find_median(stack_a, ft_lstsize(*stack_a));
	while ((*stack_a)->flag == 0)
	{
		if ((*stack_a)->content <= median->xs)
			pb(stack_a, stack_b);
		else if ((*stack_a)->flag == 0)
		{
			(*stack_a)->flag = -1;
			ra(stack_a, true);
		}
	}
	second(stack_a, stack_b, median);
	third(stack_a, stack_b, median);
	fourth(stack_a, stack_b, median);
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
	ft_lst_free(stack_a);
	free(median);
}

static void	second(t_list **stack_a, t_list **stack_b, t_median *median)
{
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
	while ((*stack_a)->flag < 1)
	{
		if ((*stack_a)->content <= (*median).s && (*stack_a)->flag < 1)
			pb(stack_a, stack_b);
		if ((*stack_a)->content > (*median).s)
			ra(stack_a, true);
	}
	while ((*stack_a)->flag == 1)
		ra(stack_a, true);
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
	while ((*stack_a)->flag < 1)
	{
		if ((*stack_a)->content <= (*median).sm && (*stack_a)->flag < 1)
			pb(stack_a, stack_b);
		if ((*stack_a)->content > (*median).sm)
			ra(stack_a, true);
	}
	while ((*stack_a)->flag == 1)
		ra(stack_a, true);
}

static void	third(t_list **stack_a, t_list **stack_b, t_median *median)
{
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
	while ((*stack_a)->flag < 1)
	{
		if ((*stack_a)->content <= (*median).m && (*stack_a)->flag < 1)
			pb(stack_a, stack_b);
		if ((*stack_a)->content > (*median).m)
			ra(stack_a, true);
	}
	while ((*stack_a)->flag == 1)
		ra(stack_a, true);
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
	while ((*stack_a)->flag < 1)
	{
		if ((*stack_a)->content <= (*median).ml && (*stack_a)->flag < 1)
			pb(stack_a, stack_b);
		if ((*stack_a)->content > (*median).ml)
			ra(stack_a, true);
	}
	while ((*stack_a)->flag == 1)
		ra(stack_a, true);
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
}

static void	fourth(t_list **stack_a, t_list **stack_b, t_median *median)
{
	while ((*stack_a)->flag < 1)
	{
		if ((*stack_a)->content <= (*median).l)
			pb(stack_a, stack_b);
		else if ((*stack_a)->flag < 1)
			ra(stack_a, true);
	}
	while (ft_lstlast(*stack_a)->flag < 1)
		rra(stack_a, true);
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
	while ((*stack_a)->flag < 1)
	{
		if ((*stack_a)->content <= (*median).xl)
			pb(stack_a, stack_b);
		else if ((*stack_a)->flag < 1)
			ra(stack_a, true);
	}
	while (ft_lstlast(*stack_a)->flag < 1)
		rra(stack_a, true);
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
	while ((*stack_a)->flag < 1)
		pb(stack_a, stack_b);
}
