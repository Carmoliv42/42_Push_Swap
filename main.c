/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:23:12 by carmoliv          #+#    #+#             */
/*   Updated: 2025/11/13 20:50:45 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stacks(t_stack *a, t_stack *b)
{
	if (a->arr)
		free(a->arr);
	if (b->arr)
		free(b->arr);
}

static void	error_exit(t_stack *a, t_stack *b, char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	free_stacks(a, b);
	exit(1);
}

static void	init_stacks(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;
	long	num;

	a->size = argc - 1;
	b->size = 0;
	a->arr = malloc(sizeof(int) * a->size);
	b->arr = malloc(sizeof(int) * a->size);
	if (!a->arr || !b->arr)
		error_exit(a, b, "malloc error");
	i = 0;
	while (i < a->size)
	{
		if (!is_number(argv[i + 1]))
			error_exit(a, b, "Error: invalid number");
		num = atoll_check(argv[i + 1]);
		if (num == 2147483648LL)
			error_exit(a, b, "Error: number out of range");
		a->arr[i++] = (int)num;
	}
	if (duplicates(a->arr, a->size))
		error_exit(a, b, "Error: duplicates");
}

static void	sort_dispatch(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
	else if (a->size <= 10)
		sort_small(a, b);
	else
		radix_sort_chunks(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	init_stacks(&a, &b, argc, argv);
	if (is_sorted(&a))
	{
		free_stacks(&a, &b);
		return (0);
	}
	sort_dispatch(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
