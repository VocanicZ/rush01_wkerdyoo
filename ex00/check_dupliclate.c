static int **board;

int  *checkDuplicate(int size, int **board) {
        int i;
        int j;
        int k;

        i = 0;
        j = 0;
        k = 1;
        while (i < size) {
            while (j < size) {
                while (k < size - 1) {
                    // using for row loop 
                    if (board[i][j] == board[i][k]) {

                        return board[i][board[i][k]];
                    }
                    //using for col loop
                    if (board[i][j] == board[k][i]) {
                        return board[i][board[i][k]];
                    }
                    k++;
                }
                j++;
            }
            i++;
        }
        return  0;
    }