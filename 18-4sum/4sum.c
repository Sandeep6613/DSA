/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b) -
           (*(int *)a < *(int *)b);
}

int** fourSum(int* nums, int numsSize, int target,
              int* returnSize, int** returnColumnSizes)
{
    int capacity = 100;
    int count = 0;

    int **result = malloc(capacity * sizeof(int *));

    *returnSize = 0;
    *returnColumnSizes = NULL;

    qsort(nums, numsSize, sizeof(int), compare);

    *returnColumnSizes = malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < numsSize - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right)
            {
                long long sum = (long long)nums[i] +
                                nums[j] +
                                nums[left] +
                                nums[right];

                if (sum == target)
                {
                    if (count == capacity)
                    {
                        capacity *= 2;
                        result = realloc(result,
                                         capacity * sizeof(int *));
                        *returnColumnSizes = realloc(
                            *returnColumnSizes,
                            capacity * sizeof(int));
                    }

                    result[count] = malloc(4 * sizeof(int));

                    result[count][0] = nums[i];
                    result[count][1] = nums[j];
                    result[count][2] = nums[left];
                    result[count][3] = nums[right];

                    (*returnColumnSizes)[count] = 4;
                    count++;

                    left++;
                    right--;

                    while (left < right &&
                           nums[left] == nums[left - 1])
                        left++;

                    while (left < right &&
                           nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }

    *returnSize = count;
    return result;
}
