#include "push_swap.h"

// retorna array de índices
int *index_array(int *arr, int size)
{ 
    int *idx;
    int i;
    int count;
    int j;
    
    idx = malloc(sizeof(int) * size);
    i = 0;
    if (!idx)
        return NULL;
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
    return idx;
}

// retorna número de bits do maior índice
int max_bits(t_stack *a)
{
    int max;
    int i;
    int bits;

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
    return bits;
}

// Calcula número de chunks baseado no tamanho
int get_chunk_count(int size)
{
    if (size <= 100)
        return 5;   // 5 chunks para até 100 elementos
    else
        return 11;  // 11 chunks para mais de 100 elementos
}

/*void radix_sort_chunks(t_stack *a, t_stack *b)
{
    int size;
    int *idx;
    int i;
    int chunks;
    int chunk_size;
    int c;
    int min;
    int max;
    int count;
    int total;
    int max_idx;
    int r;

    size = a->size;
    idx = index_array(a->arr, size);
    if (!idx)
        return;
    i = 0;
    while (i < size)
    {
        a->arr[i] = idx[i];
        i++;
    }
    free(idx);

    chunks = get_chunk_count(size);

    // calcular tamanho do chunk sem ternário
    if (size % chunks != 0)
        chunk_size = size / chunks + 1;
    else
        chunk_size = size / chunks;

    c = 0;
    while (c < chunks)
    {
        min = c * chunk_size;
        max = (c + 1) * chunk_size - 1;
        if (max >= size)
            max = size - 1;

        count = 0;
        total = a->size;
        while (count < total)
        {
            if (a->arr[0] >= min && a->arr[0] <= max)
                pb(a, b);
            else
                ra(a);
            count++;
        }
        c++;
    }

    // Trazer de volta de B para A
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
        {
            while (max_idx > 0)
            {
                rb(b);
                max_idx--;
            }
        }
        else
        {
            r = b->size - max_idx;
            while (r > 0)
            {
                rrb(b);
                r--;
            }
        }
        pa(a, b);
    }
}*/
