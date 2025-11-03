#include "push_swap.h"

void sa(t_stack *a)
{
    if (a->size < 2) return;
    int tmp = a->arr[0];
    a->arr[0] = a->arr[1];
    a->arr[1] = tmp;
    ft_printf("sa\n");
}

void sb(t_stack *b)
{
    if (b->size < 2) return;
    int tmp = b->arr[0];
    b->arr[0] = b->arr[1];
    b->arr[1] = tmp;
    ft_printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}