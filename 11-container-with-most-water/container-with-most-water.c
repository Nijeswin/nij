#include <stdio.h>

int maxArea(int height[], int n) {
    int left = 0, right = n - 1;
    int max_water = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int width = right - left;
        int area = h * width;

        if (area > max_water)
            max_water = area;

        // Move the pointer with smaller height
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max_water;
}

int mains() {
    int n;
    scanf("%d", &n);

    int height[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    printf("%d", maxArea(height, n));

    return 0;
}
