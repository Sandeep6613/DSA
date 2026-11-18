/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;

    return (x[0] > y[0]) - (x[0] < y[0]);
}

int** merge(int** intervals, int intervalsSize,
            int* intervalsColSize,
            int* returnSize,
            int** returnColumnSizes) {

    qsort(intervals, intervalsSize,
          sizeof(int*), compare);

    int** result = malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));

    int count = 0;

    for (int i = 0; i < intervalsSize; i++) {

        int start = intervals[i][0];
        int end = intervals[i][1];
        if (count > 0 && start <= result[count - 1][1]) {

            if (end > result[count - 1][1]) {
                result[count - 1][1] = end;
            }

        } else {

            result[count] = malloc(2 * sizeof(int));

            result[count][0] = start;
            result[count][1] = end;

            (*returnColumnSizes)[count] = 2;

            count++;
        }
    }

    *returnSize = count;

    return result;
}
