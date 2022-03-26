#include <stdlib.h>
#include "ft_ft.c"
#include "ft_logic.c"

int *split_input(char *str)
{
    int *array; 
    int i;
    int j;
    //col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left row3left row4left row1right row2right row3right row4right
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            j++;
        i++;
    }
    if (ft_sqrt(j)[1] != 0)
        return (error());
    array = (int *) malloc(sizeof(int) * (j + 1));
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            array[j++] = ft_atoi(str[i - 1]);
        i++;
    }
    array[j] = ft_atoi(str[i - 1]);
    return (array);
}

#include <stdio.h>
int main(int argv, char **argc)
{
    int *array_input;
    if (argv == 2)
    {
        array_input = split_input(&argc[1][0]);
        for(int i=0;i<16;i++)
            printf("%d, ", array_input[i]);
        //code here 
    }
    else
        return (error());
    return (0);
}