#include "push_swap.h"

void	index_stack(t_stack *a)
{
	int	*idx;
	int	i;

	idx = index_array(a->arr, a->size);
	if (!idx)
		return;
	i = 0;
	while (i < a->size)
	{
		a->arr[i] = idx[i];
		i++;
	}
	free(idx);
}
