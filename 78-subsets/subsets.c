/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned in *returnColumnSizes.
 * Note: Both returned array and *columnSizes must be malloced.
 */
#include <stdlib.h>

void backtrack(int* nums, int numsSize, int start,
               int* path, int pathSize,
               int** result, int* returnSize,
               int* returnColumnSizes) {

    int* subset = malloc((pathSize == 0 ? 1 : pathSize) * sizeof(int));

    for (int i = 0; i < pathSize; i++) {
        subset[i] = path[i];
    }

    result[*returnSize] = subset;
    returnColumnSizes[*returnSize] = pathSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        path[pathSize] = nums[i];

        backtrack(nums, numsSize, i + 1,
                  path, pathSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize,
              int* returnSize, int** returnColumnSizes) {

    int total = 1 << numsSize;

    int** result = malloc(total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));

    int* path = malloc(numsSize * sizeof(int));
    *returnSize = 0;

    backtrack(nums, numsSize, 0, path, 0,
              result, returnSize, *returnColumnSizes);

    free(path);

    return result;
}
