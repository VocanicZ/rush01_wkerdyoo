int array_size(int *array);

void    field_condition(int **board, int *condition)
{ 
    int i;
    int j;

    i = -1;
    while (++i < array_size(&board[0][0]))
    {
        j = -1;
        while (++j < array_size(&board[0][0]))
        {
            if (i == 0)
            {
                if (condition[j] == 1)
                    board[i][j] = array_size(condition) / 4;
                else if (condition[j] == array_size(condition) / 4)
                    board[i][j] = 1;
            }
            else if (i == array_size(&board[0][0]) - 1)
            {
                if (condition[j + array_size(condition) / 4] == 1)
                    board[i][j] = array_size(condition) / 4;
                else if (condition[j + array_size(condition) / 4] == array_size(condition) / 4)
                    board[i][j] = 1;
            }
            if (j == 0)
            {
                if (condition[i + array_size(condition) / 2] == 1)
                    board[i][j] = array_size(condition) / 4;
                else if (condition[i + array_size(condition) / 2] == array_size(condition) / 4)
                    board[i][j] = 1;
            }
            else if (j == array_size(&board[0][0]) - 1)
            {
                if (condition[i + array_size(condition) * 3 / 4] == 1)
                    board[i][j] = array_size(condition) / 4;
                else if (condition[i + array_size(condition) * 3 / 4] == array_size(condition) / 4)
                    board[i][j] = 1;
            }
        }
    }
}