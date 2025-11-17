/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:58:59 by carmoliv          #+#    #+#             */
/*   Updated: 2025/11/17 21:52:32 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// retorna array de índices
int	*index_array(int *arr, int size)
{
	int	*idx;
	int	i;
	int	count;
	int	j;

	idx = malloc(sizeof(int) * size);
	if (!idx)
		return (NULL);
	i = 0;
	while (i < size)
	{
		count = 0;
		j = 0;
		while (j < size)
		{
			if (arr[j] < arr[i])
				count++;
			j++;
		}
		idx[i] = count;
		i++;
	}
	return (idx);
}

int	max_bits(t_stack *a)
{
	int	max;
	int	i;
	int	bits;

	max = a->arr[0];
	i = 1;
	while (i < a->size)
	{
		if (a->arr[i] > max)
			max = a->arr[i];
		i++;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	else
		return (11);
}
