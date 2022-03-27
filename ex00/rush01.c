#include <stdlib.h>

void    field_condition(int **board, int *condition);

void    print_board(int **board);

int array_size(int *array);

int error(void);

int *hash_array(int *array);

int **gen_combination(int first, int last, int n);

int ft_atoi(char c);

int combination_match(int *array, int *template, int first, int last, int n);

int *checkDuplicate(int size, int **board);

int *split_input(char *str)
{
    int *array; 
    int i;
    int j;
    int k;

    i = 0;;
    j = 0;
    k = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            k++;;
        i++;
    }
    if ((k + 1) % 4 != 0 && k > 14)
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
#include <stdio.h>
void    print_line(void)
{
    printf("-------------------------------------\n");
}

int main(int argv, char **argc)
{
    int **board;
    int **tmp_board;
    int *array_input;
    int i;
    int j;
    int tmp;
    int k;
    int l;
    int *prt;
    if (argv == 2)
    {
        array_input = split_input(&argc[1][0]);
        board = gen_board(array_size(array_input) / 4);
        tmp_board = gen_board(array_size(array_input) / 4);
        print_line();
        print_board(board);
        print_line();
        field_condition(board, array_input);
        field_condition(tmp_board, array_input);
        print_board(board);
        print_line();
        i = -1;
        while (++i < array_size(array_input) / 4)
        {
            j = 0;
            tmp = combination_match(board[i], tmp_board[i], array_input[array_size(array_input) / 2 + i], array_input[array_size(array_input) / 4 * 3 + i], j);
            while (tmp != 0)
            {
                if (tmp == 2)
                    return (error());
                tmp = combination_match(board[i], tmp_board[i], array_input[array_size(array_input) / 2 + i], array_input[array_size(array_input) / 4 * 3 + i], ++j);
            }
        }
        print_board(board);

        print_line();
        i = 0;
        j = 0;
        tmp = combination_match(board[i], tmp_board[i], array_input[array_size(array_input) / 2 + i], array_input[array_size(array_input) / 4 * 3 + i], j);
        while (i < array_size(array_input) / 4)
        {
            printf("i %d j %d\n", i, j);
            tmp = combination_match(board[i], tmp_board[i], array_input[array_size(array_input) / 2 + i], array_input[array_size(array_input) / 4 * 3 + i], j);
            printf("tmp = %d\n", tmp);
            if (tmp == 3 || tmp == 1)
                j++;
            else if (tmp == 2 || tmp == 0)
            {
                i++;
                j = 0;
            }
        }

        print_board(board);
        print_line();
        print_board(combine_board_ui(board, array_input));
    }
    else
        return (error());
    return (0);
}