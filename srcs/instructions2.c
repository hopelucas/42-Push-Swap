/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:36:30 by hlucas            #+#    #+#             */
/*   Updated: 2022/05/23 16:01:52 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **stack_a, bool flag)
/*ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.*/
{
	t_list	*temp;
	t_list	*last;

	if ((*stack_a)->next == NULL)
		return ;
	last = *stack_a;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	while (temp->next)
		temp = temp->next;
	last->next = NULL;
	temp->next = last;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, bool flag)
/*rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.*/
{
	t_list	*temp;
	t_list	*last;

	if ((*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	temp = last;
	*stack_b = (*stack_b)->next;
	while (temp->next)
		temp = temp->next;
	last->next = NULL;
	temp->next = last;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, bool flag)
/*
rr : ra and rb at the same time. */
{
	ra(stack_a, false);
	rb(stack_b, false);
	if (flag)
		write(1, "rr\n", 3);
}

void	rra(t_list **list, bool flag)
/* Last element becomes first*/
{
	t_list	*curr;
	t_list	*prev;

	curr = *list;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = *list;
	prev->next = NULL;
	*list = curr;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, bool flag)
/*rra : reverse rotate b - shift down all elements of stack b by 1.
The last element becomes the first one.*/
{
	t_list	*temp;
	t_list	*first;

	if ((*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	first = temp;
	while (first->next)
	{
		first = first->next;
	}
	if (temp->next)
	{
		while (temp->next->next)
			temp = temp->next;
	}
	temp->next = NULL;
	ft_lstadd_front (stack_b, first);
	if (flag)
		write(1, "rrb\n", 4);
}
