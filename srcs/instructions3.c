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