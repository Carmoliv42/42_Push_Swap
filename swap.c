#include "push_swap.h"

void sa(t_stack *a)
{
    int tmp;

    if (a->size < 2) 
        return;
    tmp = a->arr[0];
    a->arr[0] = a->arr[1];
    a->arr[1] = tmp;
    ft_printf("sa\n");
}

void sb(t_stack *b)
{
    int tmp;
    if (b->size < 2) 
        return;
    tmp = b->arr[0];
    b->arr[0] = b->arr[1];
    b->arr[1] = tmp;
    ft_printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}