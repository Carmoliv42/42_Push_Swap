/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:21:51 by carmoliv          #+#    #+#             */
/*   Updated: 2025/11/13 20:21:54 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_chunk_size(int size, int chunks)
{
	if (size % chunks != 0)
		return (size / chunks + 1);
	return (size / chunks);
}

void	push_chunks(t_stack *a, t_stack *b, int chunks, int chunk_size)
{
	int	c;
	int	min;
	int	max;
	int	count;
	int	total;

	c = 0;
	while (c < chunks)
	{
		min = c * chunk_size;
		max = (c + 1) * chunk_size - 1;
		if (max >= a->size)
			max = a->size - 1;
		count = 0;
		total = a->size;
		while (count++ < total)
		{
			if (a->arr[0] >= min && a->arr[0] <= max)
				pb(a, b);
			else
				ra(a);
		}
		c++;
	}
}
