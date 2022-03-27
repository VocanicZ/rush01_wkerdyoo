#include <stdio.h>

void    field_condition(int **board, int *condition);

int **gen_board(int n);

void    print_board(int **board);

int *split_input(char *str);

int array_size(int *array);

int **combine_board_ui(int **board, int *ui);

int error(void);

int *hash_array(int *array);

int **gen_combination(int first, int last, int n);

void    print_line(void)
{
    printf("-------------------------------------\n");
}

int main(int argv, char **argc)
{
    int **board;
    int *array_input;
    if (argv == 2)
    {
        array_input = split_input(&argc[1][0]);
        board = gen_board(array_size(array_input) / 4);
        print_line();
        print_board(board);
        print_line();
        field_condition(board, array_input);
        print_board(board);
        print_line();
        printf("looking for hash %d %d\n", array_input[0], array_input[array_size(array_input) / 4]);
        gen_combination(array_input[0], array_input[array_size(array_input) / 4], array_size(array_input) / 4);
        print_line();
        print_board(combine_board_ui(board, array_input));
    }
    else
        return (error());
    return (0);
}