/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:22:14 by carmoliv          #+#    #+#             */
/*   Updated: 2025/11/17 21:52:00 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
