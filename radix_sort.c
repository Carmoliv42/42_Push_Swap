/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:58:59 by carmoliv          #+#    #+#             */
/*   Updated: 2025/11/13 21:02:15 by carmoliv         ###   ########.fr       */
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

// retorna número de bits do maior índice
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

// Calcula número de chunks baseado no tamanho
int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);// 5 chunks para até 100 elementos
	else
		return (11);// 11 chunks para mais de 100 elementos
}
