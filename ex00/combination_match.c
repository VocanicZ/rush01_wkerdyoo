int array_size(int *array);

int **gen_combination(int first, int last, int n);

void    print_array(int *array);
#include <stdio.h>
int combination_match(int *array, int first, int last, int n)
{
    int i;
    int j;
    int **combination;

    printf("first = %d, last =%d , n = %d, array = ", first, last, n);
    print_array(array);
    //match each row with 1st combination that cat fit with **map
    i = -1;
    j = 0;
    combination = gen_combination(first, last, array_size(array));
    while (combination[++i][0] != -1)
        j++;
    printf("n =%d, j = %d\n", n, j);
    if (n > j)
        return (2);//2
    i = -1;
    j = 0;
    while (++i < array_size(array))
    {
        if (array[i] == 0 || array[i] == combination[n][i])
            j++;
    }
    printf("j = %d, size =%d\n", j, array_size(array));
    if (j != array_size(array)) 
        return (1); //1
    i = -1;
    while (++i < array_size(array))
    {
        printf("array[%d] = %d",i , array[i]);
        if (array[i] == 0)
        {
            printf(" assign %d", combination[n][i]);
            array[i] = combination[n][i];
        }
        printf("\n");
    }
    return (0);
}