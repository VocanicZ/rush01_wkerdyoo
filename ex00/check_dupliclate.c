#include <stdlib.h>
#include <stdio.h>

int  *checkDuplicate(int size, int **board) {
        int i;
        int j;
        int k;
        int l;
        int *result;

        i = 0;
        j = 0;
        k = 1;
        result = (int *) malloc(sizeof(int) * 3);
        result[0] = -1;
        result[1] = -1;
        result[2] = -1;
        while (i < size) 
        {
            while (j < size) 
            {
                while (k < size - 1) 
                {
                    // using for row, col loop 
                    printf("compare %d <-> %d, i=%d,j=%d,k=%d\n", board[i][j], board[k][j], i,j,k);
                    if (board[i][j] == board[k][j])
                    {
                        result[0] = board[k][j];
                        result[2] = j;
                        while (board[i][j] == board[k][j])//board[i][j] == board[i][k] || board[i][j] == board[k][j]) 
                            l++;
                        result[1] = l;
                        return (result);
                    }
                    k++;
                }
                j++;
            }
            i++;
        }
        return  (result);
    }