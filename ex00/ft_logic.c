#include <stdlib.h>
#include <stdio.h>

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

int ft_pow(int  base, int n)
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

int *ft_sqrt(int n)
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
    tmp[0] = ft_pow(i - 1, 2);
    if (n - tmp[0] != 0)
        tmp[1] = 1;
    return (tmp);
}