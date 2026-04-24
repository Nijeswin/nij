#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    static char prefix[201];  // max length
    prefix[0] = '\0';

    if (strsSize == 0) return prefix;

    for (int i = 0; strs[0][i] != '\0'; i++) {
        char current = strs[0][i];

        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != current) {
                prefix[i] = '\0';
                return prefix;
            }
        }
        prefix[i] = current;
    }

    prefix[strlen(strs[0])] = '\0';
    return prefix;
}