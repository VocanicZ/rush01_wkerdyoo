#include <unistd.h>

//This file contain all function using write()

int array_size(int *array)
{
    int i;

    i = 0;
    while (*array++)
    {
        i++;
    }
    return (i);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

char    itoa(int i)
{
    char    a;

    a = i + '0';
    return (a);
}

void error(void)
{
    write(1, "Error\n", 6);
}

void print_map(int **map)
{
    int i;
    int j;

    i = -1;
    while (++i < array_size(&map[0]))
    {
        j = -1;
        while (++j < array_size(&map[0]))
        {
            ft_putchar(itoa(map[i][j]));
            ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}