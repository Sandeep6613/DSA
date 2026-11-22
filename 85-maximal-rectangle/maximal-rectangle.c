
int largestRectangleArea(int* heights, int n) {
    int stack[n + 1];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int current = (i == n) ? 0 : heights[i];

        while (top != -1 && heights[stack[top]] > current) {
            int height = heights[stack[top--]];

            int width = (top == -1) 
                        ? i 
                        : i - stack[top] - 1;

            int area = height * width;

            if (area > maxArea)
                maxArea = area;
        }

        if (i < n)
            stack[++top] = i;
    }

    return maxArea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int heights[cols];
    int maxArea = 0;

    for (int j = 0; j < cols; j++)
        heights[j] = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }
        int area = largestRectangleArea(heights, cols);

        if (area > maxArea)
            maxArea = area;
    }
    return maxArea;
}
