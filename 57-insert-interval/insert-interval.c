/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int** insert(int** intervals, int intervalsSize,
             int* intervalsColSize,
             int* newInterval,
             int newIntervalSize,
             int* returnSize,
             int** returnColumnSizes) {

    int** result = malloc((intervalsSize + 1) * sizeof(int*));

    *returnColumnSizes = malloc((intervalsSize + 1) * sizeof(int));

    int count = 0;
    int i = 0;
    while (i < intervalsSize &&
           intervals[i][1] < newInterval[0]) {

        result[count] = intervals[i];
        (*returnColumnSizes)[count] = 2;

        count++;
        i++;
    }
    while (i < intervalsSize &&
           intervals[i][0] <= newInterval[1]) {

        if (intervals[i][0] < newInterval[0]) {
            newInterval[0] = intervals[i][0];
        }

        if (intervals[i][1] > newInterval[1]) {
            newInterval[1] = intervals[i][1];
        }

        i++;
    }
    result[count] = malloc(2 * sizeof(int));

    result[count][0] = newInterval[0];
    result[count][1] = newInterval[1];

    (*returnColumnSizes)[count] = 2;
    count++;
    while (i < intervalsSize) {

        result[count] = intervals[i];
        (*returnColumnSizes)[count] = 2;

        count++;
        i++;
    }

    *returnSize = count;

    return result;
}
