/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

char ***result;
int *columnSizes;
char **board;

int cols[20];
int diag1[40];
int diag2[40];

int count;
int n;

void backtrack(int row) {
    if (row == n) {

        result[count] = malloc(n * sizeof(char *));

        for (int i = 0; i < n; i++) {
            result[count][i] = malloc(n + 1);
            strcpy(result[count][i], board[i]);
        }

        columnSizes[count] = n;
        count++;

        return;
    }
    for (int col = 0; col < n; col++) {

        int d1 = row - col + n - 1;
        int d2 = row + col;
        if (cols[col] || diag1[d1] || diag2[d2])
            continue;
        board[row][col] = 'Q';

        cols[col] = 1;
        diag1[d1] = 1;
        diag2[d2] = 1;
        backtrack(row + 1);
        board[row][col] = '.';

        cols[col] = 0;
        diag1[d1] = 0;
        diag2[d2] = 0;
    }
}

char*** solveNQueens(int N, int* returnSize,
                     int** returnColumnSizes) {

    n = N;
    count = 0;

    int capacity = 10000;

    result = malloc(capacity * sizeof(char **));
    columnSizes = malloc(capacity * sizeof(int));

    board = malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        board[i] = malloc(n + 1);
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }

    memset(cols, 0, sizeof(cols));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));

    backtrack(0);

    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);

    *returnSize = count;
    *returnColumnSizes = columnSizes;

    return result;
}
