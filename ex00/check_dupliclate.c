#include <stdlib.h>

int  *checkDuplicate(int size, int **board) {
        int i;
        int j;
        int k;
        int *result;

        i = 0;
        j = 0;
        k = 1;
        result = (int *) malloc(sizeof(int) * 3);
        result[2] = -1;
        while (i < size) {
            while (j < size) {
                while (k < size - 1) {
                    // using for row, col loop 
                    if (board[i][j] == board[i][k] || board[i][j] == board[k][j]) {
                        result[0] = i;
                        result[1] = board[i][k];
                        return result;
                    }
                    k++;
                }
                j++;
            }
            i++;
        }
        return  0;
    }