int array_size(int *array);

int **gen_combination(int first, int last, int n);

int combination_match(int *array, int *template, int first, int last, int n)
{
    int i;
    int j;
    int **combination;

    i = -1;
    j = 0;
    combination = gen_combination(first, last, array_size(array));
    while (combination[++i][0] != -1)
        j++;
    if (n > j)
        return (2);
    i = -1;
    j = 0;
    while (++i < array_size(array))
    {
        if (template[i] == 0 || template[i] == combination[n][i])
            j++;
    }
    if (j != array_size(array)) 
        return (1);
    i = -1;
    j = 0;
    while (++i < array_size(array))
    { 
        if (array[i] == combination[n][i])
            j++;
        if (template[i] == 0)
            array[i] = combination[n][i];
    }
    if (j == array_size(array))
        return (3);
    return (0);
}