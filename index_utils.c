/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:22:14 by carmoliv          #+#    #+#             */
/*   Updated: 2025/11/19 22:26:49 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	*index_array(int *arr, int size)
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

void	index_stack(t_stack *a)
{
	int	*idx;
	int	i;

	idx = index_array(a->arr, a->size);
	if (!idx)
		return ;
	i = 0;
	while (i < a->size)
	{
		a->arr[i] = idx[i];
		i++;
	}
	free(idx);
}

void	free_aux(char **aux)
{
	int	i;

	if (!aux)
		return ;
	i = 0;
	while (aux[i])
	{
		free(aux[i]);
		i++;
	}
	free(aux);
}
