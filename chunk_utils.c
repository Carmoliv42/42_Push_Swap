/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:21:51 by carmoliv          #+#    #+#             */
/*   Updated: 2025/11/22 15:09:49 by carmoliv         ###   ########.fr       */
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
	int c = 0;
	int min;
	int max;
	int	processed;

	while (c < chunks)
	{
		min = c * chunk_size;
		max = (c + 1) * chunk_size - 1;

		int total = a->size;
		processed = 0;
		while (processed < total)
		{
			if (a->arr[0] >= min && a->arr[0] <= max)
				pb(a, b);
			else
				ra(a);
			processed++;
		}
		c++;
	}
}

int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	else
		return (11);
}
