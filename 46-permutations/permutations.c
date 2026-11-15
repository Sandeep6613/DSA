/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void solve(int* nums, int n, int* used,
           int* path, int** result, int* count,
           int depth) {

    if (depth == n) {
        result[*count] = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            result[*count][i] = path[i];
        }

        (*count)++;
        return;
    }

    for (int i = 0; i < n; i++) {

        if (!used[i]) {

            used[i] = 1;
            path[depth] = nums[i];

            solve(nums, n, used, path,
                  result, count, depth + 1);

            used[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize,
              int* returnSize, int** returnColumnSizes) {

    int total = 1;

    for (int i = 1; i <= numsSize; i++) {
        total *= i;
    }

    int** result = malloc(total * sizeof(int*));
    int* used = calloc(numsSize, sizeof(int));
    int* path = malloc(numsSize * sizeof(int));

    *returnSize = 0;

    *returnColumnSizes = malloc(total * sizeof(int));

    solve(nums, numsSize, used, path,
          result, returnSize, 0);

    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    free(used);
    free(path);

    return result;
}
