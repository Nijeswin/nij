#include <stdlib.h>
#include <string.h>

void backtrack(char** result, int* returnSize, char* current, int open, int close, int n) {
    // If valid combination formed
    if (strlen(current) == 2 * n) {
        result[*returnSize] = (char*)malloc(strlen(current) + 1);
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    // Add '('
    if (open < n) {
        int len = strlen(current);
        current[len] = '(';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open + 1, close, n);
        current[len] = '\0';  // backtrack
    }

    // Add ')'
    if (close < open) {
        int len = strlen(current);
        current[len] = ')';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open, close + 1, n);
        current[len] = '\0';  // backtrack
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int capacity = 10000;
    char** result = (char**)malloc(sizeof(char*) * capacity);
    *returnSize = 0;

    char current[20] = "";  // max length = 2*n (n <= 8)

    backtrack(result, returnSize, current, 0, 0, n);

    return result;
}