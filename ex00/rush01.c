#include <stdlib.h>
#include "ft_ft.c"
#include <stdio.h>

int main(int argv, char **argc)
{
    int **board;
    int *array_input;
    if (argv == 2)
    {
        array_input = split_input(&argc[1][0]);
        board = gen_board(array_size(array_input) / 4);


        //print_map(board);
        print_board(combine_board_ui(board, array_input));
    }
    else
        return (error());
    return (0);
}