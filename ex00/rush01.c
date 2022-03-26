#include <stdlib.h>
#include "ft_ft.c"
#include <stdio.h>

int main(int argv, char **argc)
{
    int **board;
    int *array_input;
    if (argv == 2)
    {
        printf("run\n");
        array_input = split_input(&argc[1][0]);
        printf("after input strip\n");
        board = gen_board(array_size(array_input) / 4);
        printf("b4 print board\n");
        print_map(board);
        printf("after draw ui\n");
        print_map(combine_board_ui(board, array_input));
        printf("done\n");
    }
    else
        return (error());
    return (0);
}