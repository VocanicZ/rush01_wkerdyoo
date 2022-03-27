#include <stdio.h>
#include <stdlib.h>

void    field_condition(int **board, int *condition);

void    print_board(int **board);

int array_size(int *array);

int error(void);

int *hash_array(int *array);

int **gen_combination(int first, int last, int n);

int ft_atoi(char c);

int combination_match(int *array, int first, int last, int n);

int *checkDuplicate(int size, int **board);

void    print_line(void)
{
    printf("-------------------------------------\n");
}

int *split_input(char *str)
{
    int *array; 
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            k++;
        i++;
    }
    if ((k + 1) % 4 != 0)
    {
        error();
        return (NULL);
    }
    array = (int *) malloc(sizeof(int) * (k + 2));
    array[k + 1] = -1; 
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            array[j++] = ft_atoi(str[i - 1]);
        else if (ft_atoi(str[i]) > (k + 1) / 4 || ft_atoi(str[i]) == 0)
        {
            error();
            return (NULL);
        }
        i++;
    }
    array[j] = ft_atoi(str[i - 1]);
    return (array);
}

int **gen_board(int n)
{
    int i;
    int j;
    int **board;

    i = 0;
    board = (int **) malloc(sizeof(int *) * (n));
    while (i < n)
    {
        board[i] = (int *) malloc(sizeof(int) * (n + 1));
        j = 0;
        while (j < n)
            board[i][j++] = 0;
        board[i++][n] = -1;
    }
    return (board);
}

int **combine_board_ui(int **board, int *ui)
{
    int **ui_board;
    int i;
    int j;
    int pos[3];

    ui_board = gen_board(array_size(ui) / 4 + 2);
    i = -1;
    pos[0] = 0;
    pos[1] = array_size(ui) / 2;
    pos[2] = array_size(ui) * 3 / 4;
    while (++i < array_size(ui) / 4 + 2)
    {
        j = -1;
        while (++j < array_size(ui) / 4 + 2)
        {
            if ((i == 0 || i == array_size(ui) / 4 + 1) && j > 0 && j < array_size(ui) / 4 + 1)
                ui_board[i][j] = ui[pos[0]++];
            else if (j == 0 && i > 0 && i < array_size(ui) / 4 + 1)
                ui_board[i][j] = ui[pos[1]++];
            else if (j == array_size(ui) / 4 + 1 && i > 0 && i < array_size(ui) / 4 + 1)
                ui_board[i][j] = ui[pos[2]++];
            else if ((i > 0 && i < array_size(ui) / 4 + 1) && j > 0 && j < array_size(ui) / 4 + 1)
                ui_board[i][j] = board[i - 1][j - 1];
        }
    }
    return (ui_board);
}

int main(int argv, char **argc)
{
    int **board;
    int *array_input;
    int i;
    int j;
    int tmp;
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

        
        //left to right by row
        
        i = -1;
        while (++i < array_size(array_input) / 4)
        {
            j = 0;
            tmp = combination_match(board[i], array_input[array_size(array_input) / 2 + i], array_input[array_size(array_input) / 4 * 3 + i], j);
            while (tmp != 0)
            {
                if (tmp == 2)
                    return (error());
                tmp = combination_match(board[i], array_input[array_size(array_input) / 2 + i], array_input[array_size(array_input) / 4 * 3 + i], ++j);
            }
        }

        //printf("found break %d %d\n", checkDuplicate(array_size(array_input) / 4, board));
        print_board(board);
        print_line();
        print_board(combine_board_ui(board, array_input));
    }
    else
        return (error());
    return (0);
}