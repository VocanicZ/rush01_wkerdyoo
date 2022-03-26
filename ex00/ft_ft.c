#include <unistd.h>

int array_size(int *array);

char    ft_itoa(int i);

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

void print_board(int **board)
{
    int i;
    int j;

    i = -1;
    while (++i < array_size(&board[0][0]))
    {
        j = -1;
        while (++j < array_size(&board[0][0]))
        {
            if (board[i][j] == 0)
                ft_putchar(' ');
            else
                ft_putchar(ft_itoa(board[i][j]));
            if (j != array_size(&board[0][0]) - 1)
                ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}