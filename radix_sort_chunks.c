/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_chunks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:58:26 by carmoliv          #+#    #+#             */
/*   Updated: 2025/11/13 20:58:52 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort_chunks(t_stack *a, t_stack *b)
{
	int	size;
	int	chunks;
	int	chunk_size;

	size = a->size;
	index_stack(a);
	chunks = get_chunk_count(size);
	chunk_size = calc_chunk_size(size, chunks);
	push_chunks(a, b, chunks, chunk_size);
	push_back_sorted(a, b);
}
