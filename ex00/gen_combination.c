#include <stdlib.h>
#include <stdio.h>

int array_size(int *array);

int *hash_array(int *array);

void    ft_swap(int *a, int *b);

void    append_array(int **array, int *p);

void    remove_array(int **array, int n);

int *ft_copy(int *array);

int ft_factorial(int n);

void    print_array(int *array)
{
    for (int i = 0; i<array_size(array);i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

void    gen_all_combination(int **big_array, int *array, int index)
{
    int j;
    int *tmp;

    if (index == array_size(array) - 1)
        append_array(big_array, array);
    j = index - 1;
    while (++j < array_size(array))
    {
        tmp = ft_copy(array);
        ft_swap(&tmp[index], &tmp[j]);
        gen_all_combination(big_array, tmp, index + 1);
    }
}

int    **gen_combination(int first, int last, int n)
{
    int **all_combination;
    int *gen;
    int i;
    int j;

    i = -1;
    gen = (int *) malloc(sizeof(int) * (n + 1));
    gen[n] = -1;
    while (++i < n)
        gen[i] = i + 1;
    all_combination = (int **) malloc(sizeof(int *) * (ft_factorial(n) + 1));
    all_combination[0] = (int *) malloc(sizeof(int) * (n + 1));
    all_combination[0][0] = -1;
    gen_all_combination(all_combination, gen, 0);
    free(gen);
    i = -1;
    j = 0;
    while (++i < ft_factorial(n) - j)
    {
        if (!(hash_array(all_combination[i])[0] == first && hash_array(all_combination[i])[1] == last))
        {
            remove_array(all_combination, i);
            i--;
            j++;
        }
    }
    for (int k=0; all_combination[k][0] != -1;k++){
        print_array(all_combination[k]);
    }
    return (all_combination);
}