#include "../includes/push_swap.h"

static void	reverse(t_list **stack_a)
{
	ra(stack_a, 1);
	sa(stack_a, 1);
}

static void	sort3(t_list **stack_a)
/* this function will sort a stack_a by ascending order, smallest on top
** only works if there is 3 n */
{
	t_list	*temp;
	int		n[3];
	int		i;

	i = -1;
	temp = *stack_a;
	while (++i < 3)
	{
		n[i] = temp->content;
		temp = temp->next;
	}
	if (n[0] > n[1] && n[1] < n[2] && n[0] < n[2])
		sa(stack_a, 1);
	else if (n[0] < n[1] && n[1] > n[2] && n[0] > n[2])
		rra(stack_a, 1);
	else if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
		ra(stack_a, 1);
	else if (n[0] > n[1] && n[1] > n[2])
		reverse(stack_a);
	else if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	ft_lst_free(stack_a);
}

void	sort5(t_list **stack_a, t_list **stack_b)
/* this function will sort by ascending order into stack_a
** only works if there is 5 numbers */
{
	ft_push_smallest_a(stack_a, stack_b);
	ft_push_smallest_a(stack_a, stack_b);
	sort3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ft_lst_free(stack_a);
}

static void	ft_init_list(t_list **stack_a, char **argv)
{
	int		i;

	ft_error(argv);
	*stack_a = malloc(sizeof(t_list));
	if (!(*stack_a))
		return ;
	i = 1;
	(*stack_a)->content = ft_atoi(argv[i]);
	(*stack_a)->next = NULL;
	while (argv[++i])
	{
		ft_new_node(stack_a, ft_atoi(argv[i]));
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (argc < 3)
		return (0);
	ft_init_list(&stack_a, argv);
	if (argc == 3)
	{
		if (stack_a->content > stack_a->next->content)
			sa(&stack_a, true);
	}
	else if (argc == 4)
		sort3(&stack_a);
	else if (argc == 6)
		sort5(&stack_a, &stack_b);
	else if (argc < 15)
		sort_halves(&stack_a, &stack_b);
	else if (argc < 60)
		sort_quarters(&stack_a, &stack_b);
	else
		sort_eighths(&stack_a, &stack_b);
}