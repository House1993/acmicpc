//
// Created by 房籽呈 on 2017/5/31.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72822932
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[n - 1][m - 1]) {
            return 0;
        }
        int *dp = new int[m];
        memset(dp, 0, sizeof(int) * m);
        dp[0] = 1;
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[0][i]) {
                break;
            }
            dp[i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[i][0]) {
                dp[0] = 0;
            }
            for (int j = 1; j < m; ++j) {
                if (obstacleGrid[i][j]) {
                    dp[j] = 0;
                    continue;
                }
                dp[j] += dp[j - 1];
                // printf("i %d j %d dp %d\n", i, j, dp[j]);
            }
        }
        return dp[m - 1];
    }
};