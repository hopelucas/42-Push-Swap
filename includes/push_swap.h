#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_median {
	int	xs;
	int	s;
	int	sm;
	int	m;
	int	ml;
	int	l;
	int	xl;
}	t_median;

void		ft_lstdel_front(t_list	**lst);
void		ft_lst_copy(t_list **input, t_list **output);
void		sa(t_list **stack_a, bool flag);
void		sb(t_list **stack_b, bool flag);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a, bool flag);
void		rb(t_list **stack_b, bool flag);
void		rr(t_list **stack_a, t_list **stack_b, bool flag);
void		rra(t_list **stack_a, bool flag);
void		rrb(t_list **stack_b, bool flag);
void		rrr(t_list **stack_a, t_list **stack_b, bool flag);
void		ft_small_pa(t_list **stack_a, t_list **stack_b);
void		ft_large_pa(t_list **stack_a, t_list **stack_b);
void		sort_three(t_list **stack_a);
void		sort_quarters(t_list **stack_a, t_list **stack_b);
void		sort_halves(t_list **stack_a, t_list **stack_b);
void		sort_eighths(t_list **stack_a, t_list **stack_b);
int			ft_error(char **argv);
t_median	*find_median(t_list **lst, int l);
int			ft_find_smallest(t_list **stack, int x);
void		ft_push_smallest_a(t_list **stack_a, t_list **stack_b);
void		ft_lst_free(t_list	**lst);

#endif