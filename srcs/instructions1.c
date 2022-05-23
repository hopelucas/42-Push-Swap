/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:36:30 by hlucas            #+#    #+#             */
/*   Updated: 2022/05/23 16:12:20 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(t_list **stack_a, bool flag)
/*swap the first 2 elements at the top of stack a.
 * Do nothing if there is only one or no elements*/
{
	t_list *temp;

	if (stack_a && (*stack_a)->next)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	if (flag)
		write(1, "sa\n", 3);
}

void sb(t_list **stack_b, bool flag)
/*swap the first 2 elements at the top of stack b.
 * Do nothing if there is only one or no elements*/
{
	t_list *temp;

	if (stack_b && (*stack_b)->next)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = temp->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	if (flag)
		write(1, "sb\n", 3);
}

void ss(t_list **stack_a, t_list **stack_b)
/* swap the first two elements on top of stack a and stack b
** do nothing if only one or no elements on stack */
{
	sa(stack_a, false);
	sb(stack_b, false);
	write(1, "ss\n", 3);
}

void pa(t_list **stack_a, t_list **stack_b)
/*push a - take the first element at the top of b and put it at the top of a. Do
		nothing if b is empty.*/
{
	t_list *temp;

	if (*stack_b)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_a = *stack_b;
		*stack_b = temp;
		write(1, "pa\n", 3);
	}
}

void pb(t_list **stack_a, t_list **stack_b)
/*push b - take the first element at the top of a and put it at the top of b. Do
		nothing if a is empty.*/
{
	t_list *temp;

	if (*stack_a)
	{
		temp = (*stack_a)->next;
		if (stack_b)
			(*stack_a)->next = *stack_b;
		else
			(*stack_a)->next = NULL;
		*stack_b = *stack_a;
		*stack_a = temp;
		write(1, "pb\n", 3);
	}
}
