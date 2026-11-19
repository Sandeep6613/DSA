
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];

    int dp[m][n];

    if (obstacleGrid[0][0] == 1)
        return 0;

    dp[0][0] = 1;
    for (int j = 1; j < n; j++) {
        dp[0][j] = (obstacleGrid[0][j] == 1) ? 0 : dp[0][j - 1];
    }
    for (int i = 1; i < m; i++) {
        dp[i][0] = (obstacleGrid[i][0] == 1) ? 0 : dp[i - 1][0];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {

            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}
