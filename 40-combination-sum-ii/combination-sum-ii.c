/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* candidates, int n, int target, int start,
               int* path, int pathSize, int** result,
               int* colSize, int* returnSize) {

    if (target == 0) {
        result[*returnSize] = malloc(pathSize * sizeof(int));

        for (int i = 0; i < pathSize; i++) {
            result[*returnSize][i] = path[i];
        }

        colSize[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < n; i++) {
        if (i > start && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;

        path[pathSize] = candidates[i];
        backtrack(candidates, n, target - candidates[i],
                  i + 1, path, pathSize + 1,
                  result, colSize, returnSize);
    }
}

int** combinationSum2(int* candidates, int candidatesSize,
                     int target, int* returnSize,
                     int** returnColumnSizes) {

    *returnSize = 0;

    qsort(candidates, candidatesSize, sizeof(int), compare);

    int** result = malloc(150 * sizeof(int*));
    *returnColumnSizes = malloc(150 * sizeof(int));

    int* path = malloc(candidatesSize * sizeof(int));

    backtrack(candidates, candidatesSize, target, 0,
              path, 0, result, *returnColumnSizes, returnSize);

    free(path);

    return result;
}
