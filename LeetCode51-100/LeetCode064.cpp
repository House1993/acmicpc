//
// Created by 房籽呈 on 2017/5/31.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72822986
 */

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        if (n < 1) {
            return 0;
        }
        int m = grid[0].size();
        if (m < 1) {
            return 0;
        }
        int *dp = new int[m];
        memset(dp, 0, sizeof(int) * m);
        dp[0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i] = dp[i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < m; ++j) {
                dp[j] = grid[i][j] + min(dp[j - 1], dp[j]);
            }
        }
        return dp[m - 1];
    }
};