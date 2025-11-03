#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "ft_printf/ft_printf.h" 

typedef struct s_stack
{
    int *arr;
    int size;
} t_stack;

// movimentos
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);

// ordenação
void sort_two(t_stack *a);
void sort_three(t_stack *a);
void sort_five(t_stack *a, t_stack *b);
void radix_sort(t_stack *a, t_stack *b);
void sort_small(t_stack *a, t_stack *b);
void radix_sort_chunks(t_stack *a, t_stack *b);
void index_stack(t_stack *a);
void push_chunks(t_stack *a, t_stack *b, int chunks, int chunk_size);
void push_back_sorted(t_stack *a, t_stack *b);

// utilitários
int max_bits(t_stack *a);
int *index_array(int *arr, int size);
int is_sorted(t_stack *a);
int duplicates(int *arr, int size);
long atoll_check(const char *str);
int is_number(char *str);
int get_chunk_count(int size);
int	calc_chunk_size(int size, int chunks);


#endif
