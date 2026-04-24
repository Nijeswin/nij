#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *map[] = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char **result, int *returnSize, char *digits, int index, char *current) {
    if (digits[index] == '\0') {
        result[*returnSize] = (char *)malloc(strlen(current) + 1);
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    char *letters = map[digits[index] - '0'];
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(result, returnSize, digits, index + 1, current);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    if (digits[0] == '\0') return NULL;

    int maxSize = 1000;  // Enough for constraints
    char **result = (char **)malloc(sizeof(char *) * maxSize);

    char current[5];  // max length = 4 + null char
    current[4] = '\0';

    backtrack(result, returnSize, digits, 0, current);

    return result;
}