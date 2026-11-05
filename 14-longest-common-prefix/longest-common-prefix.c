


char* longestCommonPrefix(char** strs, int strsSize) {

    if (strsSize == 0) {
        return "";
    }

    int i = 0;

    while (strs[0][i] != '\0') {

        char ch = strs[0][i];

        for (int j = 1; j < strsSize; j++) {

            if (strs[j][i] != ch) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }

        i++;
    }

    return strs[0];
}
