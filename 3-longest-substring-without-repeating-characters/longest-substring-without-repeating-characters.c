#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int lastIndex[256];
    for (int i = 0; i < 256; i++)
        lastIndex[i] = -1;

    int maxLen = 0;
    int start = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = s[i];

        if (lastIndex[ch] >= start)
            start = lastIndex[ch] + 1;

        lastIndex[ch] = i;

        int currLen = i - start + 1;
        if (currLen > maxLen)
            maxLen = currLen;
    }
    return maxLen;
}

int mainw() {
    char s[50005];

    /* Read input string (handles spaces too) */
    fgets(s, sizeof(s), stdin);

    /* Remove newline if present */
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';

    int result = lengthOfLongestSubstring(s);

    /* Output */
    printf("%d", result);

    return 0;
}
