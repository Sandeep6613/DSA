/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {

    char** result = malloc(wordsSize * sizeof(char*));

    int i = 0;
    int count = 0;

    while (i < wordsSize) {

        int j = i;
        int letters = 0;
        while (j < wordsSize &&
               letters + strlen(words[j]) + (j - i) <= maxWidth) {

            letters += strlen(words[j]);
            j++;
        }

        int gaps = j - i - 1;
        int spaces = maxWidth - letters;

        char* line = malloc((maxWidth + 1) * sizeof(char));
        int pos = 0;
        if (j == wordsSize || gaps == 0) {

            for (int k = i; k < j; k++) {

                int len = strlen(words[k]);

                memcpy(line + pos, words[k], len);
                pos += len;

                if (k < j - 1) {
                    line[pos++] = ' ';
                }
            }
            while (pos < maxWidth) {
                line[pos++] = ' ';
            }
        }
        else {

            int spaceEach = spaces / gaps;
            int extra = spaces % gaps;

            for (int k = i; k < j; k++) {

                int len = strlen(words[k]);

                memcpy(line + pos, words[k], len);
                pos += len;

                if (k < j - 1) {

                    int totalSpaces = spaceEach;

                    if (extra > 0) {
                        totalSpaces++;
                        extra--;
                    }

                    for (int s = 0; s < totalSpaces; s++) {
                        line[pos++] = ' ';
                    }
                }
            }
        }

        line[pos] = '\0';

        result[count++] = line;
        i = j;
    }

    *returnSize = count;

    return result;
}
