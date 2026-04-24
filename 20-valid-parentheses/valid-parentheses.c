#include <stdbool.h>
#include <stdlib.h>

bool isValid(char* s) {
    int len = 0;
    while (s[len] != '\0') len++;

    char* stack = (char*)malloc(sizeof(char) * len);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // Push opening brackets
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } 
        else {
            // If stack is empty → invalid
            if (top == -1) {
                free(stack);
                return false;
            }

            char topChar = stack[top--];

            // Check matching
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }

    // If stack empty → valid
    bool result = (top == -1);
    free(stack);
    return result;
}