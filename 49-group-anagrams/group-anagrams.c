/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

#define MAX 10000

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char*** groupAnagrams(char** strs, int strsSize,
                      int* returnSize, int** returnColumnSizes) {

    char*** result = malloc(strsSize * sizeof(char**));
    int* columnSizes = calloc(strsSize, sizeof(int));

    char** sorted = malloc(strsSize * sizeof(char*));
    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {

        int found = -1;

        char* temp = malloc(strlen(strs[i]) + 1);
        strcpy(temp, strs[i]);

        qsort(temp, strlen(temp), sizeof(char), compare);

        for (int j = 0; j < groupCount; j++) {
            if (strcmp(sorted[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            found = groupCount++;

            sorted[found] = temp;
            result[found] = malloc(strsSize * sizeof(char*));
        } else {
            free(temp);
        }

        result[found][columnSizes[found]] =
            malloc(strlen(strs[i]) + 1);

        strcpy(result[found][columnSizes[found]], strs[i]);

        columnSizes[found]++;
    }

    *returnSize = groupCount;
    *returnColumnSizes = columnSizes;

    free(sorted);

    return result;
}
