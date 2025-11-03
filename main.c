#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0; // nada para ordenar

    t_stack a;
    t_stack b;
    long num;
    int i;

    a.size = argc - 1;
    b.size = 0;
    a.arr = malloc(sizeof(int) * a.size);
    b.arr = malloc(sizeof(int) * a.size);
    i = 0;
    if (!a.arr || !b.arr)
    {
        write(2, "malloc error\n", 13);
        exit(1);
    }

    // preenche stack A
    while (i < a.size)
    {
        if (!is_number(argv[i + 1]))
        {
            write(2, "Error: invalid number\n", 22);
            free(a.arr);
            free(b.arr);
            exit(1);
        }

        num = atoll_check(argv[i + 1]); // ✅ chama aqui
        if (num == 2147483648LL)
        {
            write(2, "Error: número fora do range\n", 29);
            free(a.arr);
            free(b.arr);
            exit(1);
        }

        a.arr[i] = (int)num;
        i++;
    }

    // ✅ chama aqui depois de preencher
    if (duplicates(a.arr, a.size))
    {
        write(2, "Error: números duplicados\n", 26);
        free(a.arr);
        free(b.arr);
        exit(1);
    }

    if (is_sorted(&a))
    {
        ft_printf("Stack já ordenada!!\n");
        free(a.arr);
        free(b.arr);
        return 0;
    }

    // escolhe o algoritmo de ordenação
    if (a.size == 2)
        sort_two(&a);
    else if (a.size == 3)
        sort_three(&a);
    else if (a.size <= 5)
        sort_five(&a, &b);
    else if (a.size <= 10)
        sort_small(&a, &b);   // <=10 elementos
    else
        radix_sort_chunks(&a, &b); // >10 elementos


    free(a.arr);
    free(b.arr);
    return 0;
}
