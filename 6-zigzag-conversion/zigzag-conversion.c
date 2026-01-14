char* convert(char* s, int numRows) {
    int len = strlen(s);
    
    if (numRows == 1 || numRows >= len)
        return s;

    // Allocate memory for result
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;

    int cycle = 2 * numRows - 2;

    for (int row = 0; row < numRows; row++) {
        for (int j = row; j < len; j += cycle) {
            result[index++] = s[j];

            int diag = j + cycle - 2 * row;
            if (row != 0 && row != numRows - 1 && diag < len) {
                result[index++] = s[diag];
            }
        }
    }

    result[index] = '\0';
    return result;
}
