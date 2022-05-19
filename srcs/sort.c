#include "../includes/push_swap.h"

static void	sort_quarters_helper(t_list **stack_a,
				t_list **stack_b, t_median *median);

void	sort_halves(t_list **stack_a, t_list	**stack_b)
{
	t_median	*median;

	median = find_median(stack_a, ft_lstsize(*stack_a));
	while ((*stack_a)->flag == 0)
	{
		if ((*stack_a)->content <= median->m)
			pb(stack_a, stack_b);
		else if ((*stack_a)->flag == 0)
		{
			(*stack_a)->flag = -1;
			ra(stack_a, true);
		}
	}
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
	while ((*stack_a)->flag < 1)
		pb(stack_a, stack_b);
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
	while (ft_find_smallest(stack_a, (*stack_a)->content) > 0)
		rra(stack_a, true);
	ft_lst_free(stack_a);
	free(median);
}

void	sort_quarters(t_list **stack_a, t_list	**stack_b)
{
	t_median	*median;

	median = find_median(stack_a, ft_lstsize(*stack_a));
	while ((*stack_a)->flag == 0)
	{
		if ((*stack_a)->content <= median->s)
			pb(stack_a, stack_b);
		else if ((*stack_a)->flag == 0)
		{
			(*stack_a)->flag = -1;
			ra(stack_a, true);
		}
	}
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
	while ((*stack_a)->flag < 1)
	{
		if ((*stack_a)->content <= median->m && (*stack_a)->flag < 1)
			pb(stack_a, stack_b);
		if ((*stack_a)->content > median->m)
			ra(stack_a, true);
	}
	while ((*stack_a)->flag == 1)
		ra(stack_a, true);
	sort_quarters_helper(stack_a, stack_b, median);
}

static void	sort_quarters_helper(t_list **stack_a,
				t_list **stack_b, t_median *median)
{
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
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
		pb(stack_a, stack_b);
	while (*stack_b)
		ft_small_pa(stack_a, stack_b);
	ft_lst_free(stack_a);
	free(median);
}