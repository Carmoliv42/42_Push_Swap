/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:15:30 by carmoliv          #+#    #+#             */
/*   Updated: 2025/11/13 21:41:54 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2 elementos
void	sort_two(t_stack *a)
{
	if (a->size == 2 && a->arr[0] > a->arr[1])
		sa(a);
}

// 3 elementos
void	sort_three(t_stack *a)
{
	if (a->arr[0] < a->arr[1] && a->arr[1] < a->arr[2])
		return ;
	else if (a->arr[0] > a->arr[1] && a->arr[1] < a->arr[2]
		&& a->arr[0] < a->arr[2])
		sa(a);
	else if (a->arr[0] > a->arr[1] && a->arr[1] > a->arr[2])
	{
		sa(a);
		rra(a);
	}
	else if (a->arr[0] > a->arr[1] && a->arr[1] < a->arr[2]
		&& a->arr[0] > a->arr[2])
		ra(a);
	else if (a->arr[0] < a->arr[1] && a->arr[1] > a->arr[2]
		&& a->arr[0] < a->arr[2])
	{
		sa(a);
		ra(a);
	}
	else if (a->arr[0] < a->arr[1] && a->arr[1] > a->arr[2]
		&& a->arr[0] > a->arr[2])
		rra(a);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min_idx;
	int	r;

	min_idx = 0;
	r = 1;
	while (r < a->size)
	{
		if (a->arr[r] < a->arr[min_idx])
			min_idx = r;
		r++;
	}
	if (min_idx <= a->size / 2)
		while (min_idx-- > 0)
			ra(a);
	else
	{
		r = a->size - min_idx;
		while (r-- > 0)
			rra(a);
	}
	pb(a, b);
}

// 4 ou 5 elementos
void	sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

// 6 a 10 elementos
void	sort_small(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
