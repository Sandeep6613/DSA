/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int result[1024][10];
int colSizes[1024];
int path[10];
int count;

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int start, int depth) {

    colSizes[count] = depth;

    for (int i = 0; i < depth; i++) {
        result[count][i] = path[i];
    }

    count++;

    for (int i = start; i < numsSize; i++) {

        if (i > start && nums[i] == nums[i - 1])
            continue;

        path[depth] = nums[i];

        backtrack(nums, numsSize, i + 1, depth + 1);
    }
}

int** subsetsWithDup(int* nums, int numsSize,
                     int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);

    count = 0;

    backtrack(nums, numsSize, 0, 0);

    int** ans = malloc(count * sizeof(int*));

    *returnColumnSizes = malloc(count * sizeof(int));

    for (int i = 0; i < count; i++) {

        ans[i] = malloc(colSizes[i] * sizeof(int));

        for (int j = 0; j < colSizes[i]; j++) {
            ans[i][j] = result[i][j];
        }

        (*returnColumnSizes)[i] = colSizes[i];
    }

    *returnSize = count;

    return ans;
}
