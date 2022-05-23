/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlucas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:36:30 by hlucas            #+#    #+#             */
/*   Updated: 2022/05/23 16:18:22 by hlucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
	return (true);
}

static void	bubble_sort(int arr[], int n)
// A function to implement bubble sort
{
	int		i;
	int		j;
	bool	swapped;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swapped = swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	if (!swapped)
		exit(0);
}

static void	assign(t_median *median, int *array, int l)
{
	bubble_sort(array, l);
	median->s = array[l / 4];
	median->m = array[l / 2];
	median->l = array[l * 3 / 4];
	median->xs = array[l / 8];
	median->sm = array[l * 3 / 8];
	median->ml = array[l * 5 / 8];
	median->xl = array[l * 7 / 8];
}

t_median	*find_median(t_list **lst, int l)
{
	int			*array;
	int			i;
	t_list		*tmp;
	t_median	*median;

	median = NULL;
	array = (int *)malloc(l);
	median = malloc(sizeof(t_median));
	tmp = *lst;
	if (!array || !median)
		return (NULL);
	i = 0;
	while (i < l)
	{
		array[i++] = tmp->content;
		tmp = tmp->next;
	}
	assign(median, array, l);
	free(array);
	return (median);
}
