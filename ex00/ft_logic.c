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
    while (++i < array_size(array))
    {
        if (i == 0)
        {
            max = array[0];
            r_max = array[array_size(array) - 1];
        }
        else 
        {
            if (array[i] > max)
            {
                hash[0]++;
                max = array[i];
            }
            if (array[array_size(array) - i] > r_max)
            {
                hash[1]++;
                r_max = array[array_size(array) - i];
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

void    remove_array(int **array, int n)
{
    int i;

    i = 0;
    while (i < n)
        i++;
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