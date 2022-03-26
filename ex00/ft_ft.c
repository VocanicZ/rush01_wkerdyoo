#include <unistd.h>
#include "ft_logic.c"

//This file contain all function using write()
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int error(void)
{
    write(1, "Error\n", 6);
    return (0);
}

void print_board(int **map)
{
    int i;
    int j;

    i = -1;
    while (++i < array_size(&map[0][0]))
    {
        j = -1;
        while (++j < array_size(&map[0][0]))
        {
            if (map[i][j] == 0)
                ft_putchar(' ');
            else
                ft_putchar(ft_itoa(map[i][j]));
            ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}