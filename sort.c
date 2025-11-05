#include "push_swap.h"

// 2 elementos
void sort_two(t_stack *a)
{
    if (a->size == 2 && a->arr[0] > a->arr[1])
        sa(a);
}

// 3 elementos
void sort_three(t_stack *a)
{
    if (a->arr[0] < a->arr[1] && a->arr[1] < a->arr[2])
        return;
    else if (a->arr[0] > a->arr[1] && a->arr[1] < a->arr[2] && a->arr[0] < a->arr[2])
        sa(a);
    else if (a->arr[0] > a->arr[1] && a->arr[1] > a->arr[2])
    {
        sa(a);
        rra(a);
    }
    else if (a->arr[0] > a->arr[1] && a->arr[1] < a->arr[2] && a->arr[0] > a->arr[2])
        ra(a);
    else if (a->arr[0] < a->arr[1] && a->arr[1] > a->arr[2] && a->arr[0] < a->arr[2])
    {
        sa(a);
        ra(a);
    }
    else if (a->arr[0] < a->arr[1] && a->arr[1] > a->arr[2] && a->arr[0] > a->arr[2])
        rra(a);
}

// 4 ou 5 elementos
void sort_five(t_stack *a, t_stack *b)
{
    while (a->size > 3)
    {
        int min_idx;
        int i;
        int r;

        min_idx = 0;
        i = 1;
        while (i < a->size)
        {
            if (a->arr[i] < a->arr[min_idx])
                min_idx = i;
            i++;
        }
        if (min_idx <= a->size / 2)
            while (min_idx-- > 0)
                ra(a);
        else
        {
            r = a->size - min_idx;
            while (r-- > 0)
                rra(a);
        }
        pb(a, b);
    }
    sort_three(a);
    while (b->size > 0)
        pa(a, b);
}

// 6 a 10 elementos
void sort_small(t_stack *a, t_stack *b) {
    while (a->size > 3) 
    {
        int min_idx;
        int i;
        int r;

        min_idx = 0;
        i = 1;
        while (i < a->size)
        {
            if (a->arr[i] < a->arr[min_idx])
                min_idx = i;
            i++;
        }
        if (min_idx <= a->size / 2)
            while (min_idx-- > 0) 
                ra(a);
        else 
        {
            r = a->size - min_idx;
            while (r-- > 0) 
                rra(a);
        }
        pb(a, b);
    }
    sort_three(a);
    while (b->size > 0)
        pa(a, b);
}
