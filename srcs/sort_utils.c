#include "../includes/push_swap.h"

static void	small_pa_helper(t_list **stack_a, t_list **stack_b);
static void	ft_push_smallest_a_help(t_list **stack_a, int i, int n);

int	ft_find_smallest(t_list **stack, int x)
{
	t_list	*temp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->content < x)
		{
			x = temp->content;
			j = i;
		}
		temp = temp->next;
		i++;
	}
	return (j);
}

void	ft_small_pa(t_list **stack_a, t_list **stack_b)
/* will find the shortest way to rotate the smallest value of the stack to the top
** will sort largest value if encountered on the way */
{
	int	location_small;
	int	argc;

	if (stack_b)
		argc = ft_lstsize(*stack_b);
	else
		argc = 0;
	location_small = ft_find_smallest(stack_b, 2147483647);
	if (location_small < argc / 2)
	{
		while (location_small != 0 && *stack_b != NULL)
		{
			rb(stack_b, 1);
			location_small--;
		}
	}
	else
	{
		while (location_small < argc && *stack_b != NULL)
		{
			rrb(stack_b, 1);
			location_small++;
		}
	}
	small_pa_helper(stack_a, stack_b);
}

static void	small_pa_helper(t_list **stack_a, t_list **stack_b)
{
	pa(stack_a, stack_b);
	(*stack_a)->flag = 1;
	ra(stack_a, 1);
}

void	ft_push_smallest_a(t_list **stack_a, t_list **stack_b)
/* this function will push the smallest found integer of stack_a to stack_b */
{
	int		i;
	int		x;
	int		n;
	t_list	*temp;

	i = 0;
	n = 0;
	temp = *stack_a;
	x = temp->content;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		if (x > temp->content)
		{
			n = i;
			x = temp->content;
		}
	}
	if (n != 0)
		ft_push_smallest_a_help(stack_a, i, n);
	pb(stack_a, stack_b);
}

static void	ft_push_smallest_a_help(t_list **stack_a, int i, int n)
/* this will swap the found value to the top of the stack_a
** in the shortest way */
{
	if (n < 3)
	{
		i = 0;
		while (i < n)
		{
			ra(stack_a, 1);
			i++;
		}
	}
	else
	{
		while (i >= n)
		{
			rra(stack_a, 1);
			i--;
		}
	}
}