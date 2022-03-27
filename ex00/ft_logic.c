#include <stdlib.h>

int error(void);

int array_size(int *array)
{
    int i;

    i = 0;
    while (array[i] != -1)
        i++;
    return (i);
}

char    ft_itoa(int i)
{
    char    a;

    a = i + '0';
    return (a);
}

int ft_atoi(char c)
{
    int i;
    
    i = c - '0';
    return (i);
}

int ft_pow(int  base, int n) //not use
{
    int tmp;

    tmp = 1;
    while (n > 0)
    {
        tmp *= base;
        n--;
    }
    return (tmp);
}

int *ft_sqrt(int n) //not use
{
    int i;
    int *tmp;

    i = 1;
    tmp = (int *) malloc(sizeof(int) * 3);
    tmp[1] = 0;
    tmp[3] = -1;
    while (ft_pow(i, 2) <= n)
    {
        i++;
    }
    tmp[0] = i - 1;
    if (n - ft_pow(tmp[0], 2) != 0)
        tmp[1] = 1;
    return (tmp);
}
#include <stdio.h>
int *hash_array(int *array)
{
    int *hash;
    int max;
    int r_max;
    int i;

    i = -1;
    hash = (int *) malloc(sizeof(int) * 3);
    hash[0] = 1;
    hash[1] = 1;
    hash[2] = -1;
    //printf("size = %d\n", array_size(array));
    while (++i < array_size(array))
    {
        if (i == 0)
        {
            max = array[0];
            r_max = array[array_size(array) - 1];
            //printf("rmax = %d\n", r_max);
        }
        else 
        {
            if (array[i] > max)
            {
                hash[0]++;
                max = array[i];
            }
            if (array[array_size(array) - i - 1] > r_max)
            {
                hash[1]++;
                r_max = array[array_size(array) - i - 1];
            }
        }
    }
    return (hash);
}

int *ft_copy(int *array)
{
    int *tmp;
    int i;

    tmp = (int *) malloc(sizeof(int) * (array_size(array) + 1));
    tmp[array_size(array)] = -1;
    i = -1;
    while (++i < array_size(array))
        tmp[i] = array[i];
    return (tmp);
}

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    append_array(int **array, int *p)
{
    int i;

    i = 0;
    while (array[i][0] != -1)
        i++;
    array[i] = p;
    array[i + 1] = (int *) malloc(sizeof(int) * (array_size(array[i]) + 1));
    array[i + 1][0] = -1;
}
void    print_array(int *array);
#include <stdio.h>
void    remove_array(int **array, int n) //array store [[],[],[],[-1],[-1]] 
{
    int i;

    i = n;
    while (array[i + 1][0] != -1)
    {
        array[i] = array[i + 1];
        i++;
    }
    array[i++][0] = -1;
    free(array[i]);
}

int ft_factorial(int n)
{
    int i;
    int fac;

    i = n;
    fac = 1;
    while (i > 0)
        fac *= i--;   
    return (fac);
}