int array_size(int *array);

int **gen_combination(int first, int last, int n);

int combination_match(int *array, int first, int last, int n)
{
    int i;
    int j;
    int **combination;
    //match each row with 1st combination that cat fit with **map
    i = -1;
    j = 0;
    combination = gen_combination(first, last, array_size(array)); 
    while (combination[i][0] != 0)
        j++;
    if (n > j)
        return (2);
    i = -1;
    while (++i < array_size(array))
    {
        if (!(array[i] == 0 || array[i] == combination[n][i]))
            j++;
    }
    if (j != array_size(array)) 
        return (1);
    i = -1;
    while (++i < array_size(array))
    {
        if (array[i] == 0)
            array[i] = combination[n][i];
    }
    return (0);
}