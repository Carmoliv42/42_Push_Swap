#include "push_swap.h"

void	push_back_sorted(t_stack *a, t_stack *b)
{
	int	max_idx;
	int	r;
	int	i;

	while (b->size > 0)
	{
		max_idx = 0;
		i = 1;
		while (i < b->size)
		{
			if (b->arr[i] > b->arr[max_idx])
				max_idx = i;
			i++;
		}
		if (max_idx <= b->size / 2)
			while (max_idx-- > 0)
				rb(b);
		else
		{
			r = b->size - max_idx;
			while (r-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}
